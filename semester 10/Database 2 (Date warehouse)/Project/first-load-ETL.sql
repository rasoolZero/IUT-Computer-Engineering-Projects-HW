
--------------------
--- SOURCE TO SA SECTION
---------------------

create or replace PROCEDURE sa.public.first_load_countries() as $$
BEGIN
	
	truncate "public".countries;
	insert into "public".countries
	select country_code,country_name 
	from "source".countries;
	commit;
end;
$$ language plpgsql;

create or replace PROCEDURE sa.public.first_load_coupons() as $$
BEGIN
		
	truncate "public".coupons;
	insert into "public".coupons
	select coupon_code,coupon_effective_until,coupon_discount
	from "source".coupons;
	commit;
end;
$$ language plpgsql;

create or replace PROCEDURE sa.public.first_load_games() as $$
BEGIN
	
	truncate "public".games;
	insert into "public".games
	select game_id,game_name,price,min_memory_size,is_online,max_no_players,details
	from "source".games;
	commit;
end;
$$ language plpgsql;


create or replace PROCEDURE sa.public.first_load_users() as $$
BEGIN
	
	truncate "public".users;
	insert into "public".users
	select user_id,email_address,first_name,last_name,birth_date,country_code
	from "source".users;
	commit;
end;
$$ language plpgsql;


create or replace PROCEDURE sa.public.first_load_orders() as $$
BEGIN
	
	truncate "public".orders;
	insert into "public".orders
	select order_id,user_id,order_date,order_status,coupon_code
	from "source".orders
	commit;
	
end;
$$ language plpgsql;


create or replace PROCEDURE sa.public.first_load_order_games() as $$
BEGIN
	
	truncate "public".order_games;
	insert into "public".order_games
	select order_id,game_id,game_price,price_after_discount
	from "source"."order_games"
	commit;
	
end;
$$ language plpgsql;



create or replace procedure sa.public.first_load_source_to_sa_etl() as $$
BEGIN
	create extension if not exists postgres_fdw;
	CREATE SERVER if not exists "source_server"
	FOREIGN DATA WRAPPER postgres_fdw
	OPTIONS (host 'localhost', dbname 'source', port '5432');
	drop user mapping IF EXISTS for "postgres" server "source_server";
	create user mapping for "postgres" server "source_server" options(user 'postgres', password '1234qwer');
	
	drop FOREIGN table if exists "source"."users";
	drop FOREIGN table if exists "source"."order_games";
	drop FOREIGN table if exists "source"."countries";
	drop FOREIGN table if exists "source"."games";
	drop FOREIGN table if exists "source"."coupons";
	drop FOREIGN table if exists "source"."orders";


	IMPORT FOREIGN SCHEMA "public" LIMIT TO (countries,order_games,users,games,coupons,orders)
    FROM SERVER "source_server" INTO "source";
	commit;
	
	
	call sa.public.first_load_countries();
	call sa.public.first_load_coupons();
	call sa.public.first_load_games();
	call sa.public.first_load_users();
	call sa.public.first_load_orders();
	call sa.public.first_load_order_games();
	
	
	
	drop FOREIGN table if exists "source"."users";
	drop FOREIGN table if exists "source"."order_games";
	drop FOREIGN table if exists "source"."countries";
	drop FOREIGN table if exists "source"."games";
	drop FOREIGN table if exists "source"."coupons";
	drop FOREIGN table if exists "source"."orders";
end;
$$ language plpgsql;




----------------------
--- SA TO DW SECTION
----------------------

create or replace PROCEDURE dw.public.first_load_orders_dim() as $$
BEGIN
	
	truncate "public".orders_dim_scd1;
	insert into "public".orders_dim_scd1
	select order_id,o.coupon_code,coupon_effective_until,coupon_discount,order_status
	from "sa"."orders" as o left join "sa"."coupons" as c on (o.coupon_code = c.coupon_code);
	commit;
END;
$$ LANGUAGE plpgsql;


create or replace PROCEDURE dw.public.first_load_games_dim() as $$
BEGIN
	
	ALTER SEQUENCE game_dim_scd2_game_key_seq RESTART;
	truncate "public".game_dim_scd2;
	insert into "public".game_dim_scd2 (game_id,game_name,min_memory_size,is_online,max_no_players,details,price,price_start_date,price_end_date,price_current_flag)
	select game_id,game_name,min_memory_size,is_online,max_no_players,details,price,CURRENT_DATE,NULL,TRUE
	from "sa"."games";
	commit;

END;
$$ LANGUAGE plpgsql;



create or replace procedure dw.public.first_load_users_dim() as $$
BEGIN
	truncate "public".users_dim_scd3;
	insert into "public".users_dim_scd3
	select user_id,email_address,first_name,last_name,birth_date,c.country_code,c.country_name,null,null,null,null,c.country_code,c.country_name
	from "sa"."users" as u join "sa"."countries" as c on (u.country_code = c.country_code);
	commit;

END
$$ LANGUAGE plpgsql;




create or replace procedure dw.public.first_load_fact_orders_transactional() as $$
declare 
	max_date date;
BEGIN
	truncate "temp".temp_agg;
	truncate "temp".temp_og;
	truncate "public".fact_orders_transactional;
	
	select CURRENT_DATE - interval '1 day' into max_date;
	
	insert into "temp".temp_agg
	select order_id,null,min(game_price),max(game_price),null,null,count(game_id),null
	from "sa".order_games as og
	group by order_id;
	commit;
	
	insert into "temp".temp_og
	select so.order_id,user_id,order_date,null,null,game_key,sog.game_price,sog.price_after_discount
	from "sa".orders as so join "sa".order_games as sog on (so.order_id = sog.order_id)
	join "public".game_dim_scd2 as gd on (sog.game_id = gd.game_id)
	where gd.price_current_flag and (order_date <= max_date);
	commit;
	
	insert into "public".fact_orders_transactional
	select order_id,user_id,game_id,to_char(order_date, 'YYYYMMDD')::int,game_price,price_after_discount,cgp,egp,games_count
	from "temp".temp_og as t1 join "temp".temp_agg as t2 on (t2.id = t1.order_id);
	commit;
	
END
$$ LANGUAGE plpgsql;




create or replace procedure dw.public.first_load_fact_orders_monthly() as $$
declare 
	loop_date date;
	end_date date;
BEGIN
	select min (order_date) from "sa"."orders" into loop_date;
	select max (order_date) from "sa"."orders" into end_date;

	truncate "temp".temp_agg;
	truncate "temp".temp_og;
	truncate "public".fact_orders_periodic_monthly;
	
	insert into "temp".temp_og
	select o.order_id,user_id,order_date,order_status,coupon_code,game_id,game_price,price_after_discount FROM
	"sa".orders as o join "sa".order_games as og on (o.order_id = og.order_id);
	
	
	WHILE to_char(loop_date,'YYYYMM')::int < to_char(end_date,'YYYYMM')::int 
	LOOP
		insert into "temp".temp_agg
		select user_id,to_char(loop_date,'YYYYMM01')::int,min(game_price),max(game_price),avg(game_price),sum(game_price),count(game_id),count(distinct(order_id))
		from "temp".temp_og
		where to_char(loop_date,'YYYYMM')::int = to_char(order_date,'YYYYMM')::int
		group by user_id;
		commit;
		select loop_date + interval '1 month' into loop_date;
	END LOOP;

	insert into "public".fact_orders_periodic_monthly 
	select id,time_key,cgp,egp,agp,tgp,number_of_orders,games_count
	from "temp".temp_agg;
	commit;
	
END
$$ LANGUAGE plpgsql;



create or replace procedure dw.public.first_load_fact_orders_acc() as $$
BEGIN
	
	truncate "temp".temp_agg;
	truncate "public".fact_orders_acc;
	
	
	insert into "temp".temp_agg
	select u.user_id,null,min(cheapest_game_price),max(expensive_game_price),sum(total_game_price)/sum(total_games_bought),sum(total_game_price)
	,sum(total_games_bought),sum(number_of_orders)
	from "sa".users as u left join "public".fact_orders_periodic_monthly as opm on (u.user_id = opm.user_id)
	group by u.user_id;
	commit;
	
	insert into "public".fact_orders_acc 
	select id,cgp,egp,agp,tgp,number_of_orders,games_count
	from "temp".temp_agg;
	commit;

END
$$ LANGUAGE plpgsql;



create or replace PROCEDURE dw.public.first_load_sa_to_dw_etl() as $$
BEGIN
	create extension if not exists postgres_fdw;
	CREATE SERVER if not exists "sa_server"
	FOREIGN DATA WRAPPER postgres_fdw
	OPTIONS (host 'localhost', dbname 'sa', port '5432');
	drop user mapping IF EXISTS for "postgres" server "sa_server";
	create user mapping for "postgres" server "sa_server" options(user 'postgres', password '1234qwer');
	
	
	drop FOREIGN table if exists "sa"."order_games";
	drop FOREIGN table if exists "sa"."orders";
	drop FOREIGN table if exists "sa"."users";
	drop FOREIGN table if exists "sa"."countries";
	drop FOREIGN table if exists "sa"."games";
	drop FOREIGN table if exists "sa"."coupons";
	
	IMPORT FOREIGN SCHEMA "public" LIMIT TO (order_games,orders,users,countries,coupons,games)
    FROM SERVER "sa_server" INTO "sa";
	commit;

	
	call dw.public.first_load_orders_dim();
	call dw.public.first_load_games_dim();
	call dw.public.first_load_users_dim();
	call dw.public.first_load_fact_orders_transactional();
	call dw.public.first_load_fact_orders_monthly();
	call dw.public.first_load_fact_orders_acc();
	
	
	
	drop FOREIGN table if exists "sa"."order_games";
	drop FOREIGN table if exists "sa"."orders";
	drop FOREIGN table if exists "sa"."users";
	drop FOREIGN table if exists "sa"."countries";
	drop FOREIGN table if exists "sa"."games";
	drop FOREIGN table if exists "sa"."coupons";
	
end;
$$ language plpgsql;


----------------------------
--- MAIN FL ETL PROCEDURE
----------------------------


create or replace procedure dw.public.FL_ETL() as $$
BEGIN
	create extension if not exists dblink;
	
    begin     -- try 
				PERFORM dblink_disconnect('sa');
    exception -- catch 
			when OTHERS  then
				raise notice 'connection did not exist';
    end ; -- try..catch
	
	PERFORM dblink_connect('sa','dbname=sa user=postgres password=1234qwer');
	PERFORM dblink_exec('sa','call sa.public.first_load_source_to_sa_etl();');
	PERFORM dblink_disconnect('sa');
	
	call dw.public.first_load_sa_to_dw_etl();
end;
$$ language plpgsql;



call FL_ETL();


