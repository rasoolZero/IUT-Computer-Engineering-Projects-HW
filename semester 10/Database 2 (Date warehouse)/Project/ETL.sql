--- loggers

create or replace procedure sa.public.logger(procedure_name varchar(255),start_time timestamptz,changed_table varchar(255),records_changed int8,descrption varchar(255))
language sql
as $$
	insert into sa."public".log values (procedure_name,start_time,CURRENT_TIMESTAMP,CURRENT_TIMESTAMP - start_time,changed_table,records_changed,descrption);
$$;

create or replace procedure dw.public.logger(procedure_name varchar(255),start_time timestamptz,changed_table varchar(255),records_changed int8,descrption varchar(255))
language sql
as $$
	insert into dw."public".log values (procedure_name,start_time,CURRENT_TIMESTAMP,CURRENT_TIMESTAMP - start_time,changed_table,records_changed,descrption);
$$;



-------------------------
--- SOURCE TO SA SECTION
-------------------------


create or replace PROCEDURE sa.public.etl_countries() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	truncate "public".countries;
	insert into "public".countries
	select country_code,country_name 
	from "source".countries;
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_countries',start_time,'countries',rows_changed,'filling countries with source data');
	
end;
$$ language plpgsql;




create or replace PROCEDURE sa.public.etl_coupons() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	truncate "public".coupons;
	insert into "public".coupons
	select coupon_code,coupon_effective_until,coupon_discount
	from "source".coupons;
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_coupons',start_time,'coupons',rows_changed,'filling coupons with source data');
end;
$$ language plpgsql;



create or replace PROCEDURE sa.public.etl_games() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	truncate "public".games;
	insert into "public".games
	select game_id,game_name,price,min_memory_size,is_online,max_no_players,details
	from "source".games;
	commit;

	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger ('etl_games',start_time,'games',rows_changed,'filling games with source data');
end;
$$ language plpgsql;


create or replace PROCEDURE sa.public.etl_users() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	truncate "public".users;
	insert into "public".users
	select user_id,email_address,first_name,last_name,birth_date,country_code
	from "source".users;
	commit;

	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_users',start_time,'users',rows_changed,'filling users with source data');
end;
$$ language plpgsql;




create or replace PROCEDURE sa.public.etl_orders() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	merge into "public".orders as o
	using "source".orders as so on o.order_id = so.order_id
	when matched then 
		update set order_status = so.order_status
	when not matched THEN
		insert values (so.order_id,so.user_id,so.order_date,so.order_status,so.coupon_code);
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger ('etl_orders',start_time,'orders',rows_changed,'merging orders data from source to SA, updating status and inserting new records');
	
end;
$$ language plpgsql;



create or replace PROCEDURE sa.public.etl_order_games() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	merge into "public".order_games as og
	using "source".order_games as sog on (og.order_id = sog.order_id and og.game_id = sog.game_id)
	when matched then 
		do NOTHING
	when not matched THEN
		insert values (sog.order_id,sog.game_id,sog.game_price,sog.price_after_discount);
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger ('etl_order_games',start_time,'order_games',rows_changed,'inserting only new records into order_games');
	
end;
$$ language plpgsql;



create or replace procedure sa.public.source_to_sa_etl() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	
	create extension if not exists postgres_fdw;
	CREATE SERVER if not exists "source_server"
	FOREIGN DATA WRAPPER postgres_fdw
	OPTIONS (host 'localhost', dbname 'source', port '5432');
	drop user mapping IF EXISTS for "postgres" server "source_server";
	create user mapping for "postgres" server "source_server" options(user 'postgres', password '1234qwer');
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'preparing source server connection');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	
	
	drop FOREIGN table if exists "source"."users";
	drop FOREIGN table if exists "source"."order_games";
	drop FOREIGN table if exists "source"."countries";
	drop FOREIGN table if exists "source"."games";
	drop FOREIGN table if exists "source"."coupons";
	drop FOREIGN table if exists "source"."orders";
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'dropped all source foreign tables');
	select CURRENT_TIMESTAMP into start_time;
	commit;


	IMPORT FOREIGN SCHEMA "public" LIMIT TO (countries,order_games,users,games,coupons,orders)
    FROM SERVER "source_server" INTO "source";
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'copying source server tables into source_server foreign schema');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	

	call sa.public.etl_countries();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_countries');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call sa.public.etl_coupons();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_coupons');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call sa.public.etl_games();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call sa.public.etl_users();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_users');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call sa.public.etl_orders();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_orders');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call sa.public.etl_order_games();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'called etl_order_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	
	
	drop FOREIGN table if exists "source"."users";
	drop FOREIGN table if exists "source"."order_games";
	drop FOREIGN table if exists "source"."countries";
	drop FOREIGN table if exists "source"."games";
	drop FOREIGN table if exists "source"."coupons";
	drop FOREIGN table if exists "source"."orders";
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('source_to_sa_etl',start_time,null,rows_changed,'dropped all source foreign tables');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
end;
$$ language plpgsql;



-------------------------
--- SA TO DW SECTION
-------------------------


create or replace PROCEDURE dw.public.etl_orders_dim() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	truncate "temp".temp_orders;
	truncate "public".orders_dim_scd1;
	
	insert into "temp".temp_orders
	select order_id,o.coupon_code,coupon_effective_until,coupon_discount,order_status 
	from "sa"."orders" as o left join "sa"."coupons" as c on (o.coupon_code = c.coupon_code);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_orders_dim',start_time,'temp_orders',rows_changed,'insert orders joined coupons into temp_orders');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	insert into "public".orders_dim_scd1
	select order_id,coupon_code,coupon_effective_until,coupon_discount,order_status
	from "temp".temp_orders;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_orders_dim',start_time,'orders_dim_scd1',rows_changed,'insert all order records from temp_orders into orders_dim');
	select CURRENT_TIMESTAMP into start_time;
	commit;
END;
$$ LANGUAGE plpgsql;




create or replace PROCEDURE dw.public.etl_games_dim() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	truncate "temp".temp_games;
	
	
	insert into "temp".temp_games
	select game_key,game_id,game_name,min_memory_size,is_online,max_no_players,details,price,price_start_date,price_end_date,price_current_flag
	from "public".game_dim_scd2;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_games_dim',start_time,'temp_games',rows_changed,'copy current game_dim into temp_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	insert into "temp".temp_games
	select null,tg.game_id,tg.game_name,tg.min_memory_size,tg.is_online,tg.max_no_players,tg.details,sg.price,CURRENT_DATE,null,true
	from "temp".temp_games as tg join "sa".games as sg on (tg.game_id = sg.game_id)
	where tg.price_current_flag and tg.price != sg.price;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_games_dim',start_time,'temp_games',rows_changed,'insert records of games with new prices into temp_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	insert into "temp".temp_games
	select null,sg.game_id,sg.game_name,sg.min_memory_size,sg.is_online,sg.max_no_players,sg.details,sg.price,CURRENT_DATE,null,true
	from "temp".temp_games as tg right join "sa".games as sg on (tg.game_id = sg.game_id)
	where tg.game_id is null;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_games_dim',start_time,'temp_games',rows_changed,'insert records of new games into temp_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	update "temp".temp_games as tg
	set price_end_date = CURRENT_DATE, price_current_flag = FALSE
	from "sa".games as sg
	where tg.game_id = sg.game_id and tg.price_current_flag and sg.price != tg.price;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_games_dim',start_time,'temp_games',rows_changed,'update end_date and current_flag of games with changed prices in temp_games');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	merge into "public".game_dim_scd2 as gd
	using "temp".temp_games as tg on (tg.game_key = gd.game_key)
	when matched and not tg.price_current_flag THEN
		update set price_end_date = CURRENT_DATE, price_current_flag = false
	when not matched THEN
		insert (game_id,game_name,min_memory_size,is_online,max_no_players,details,price,price_start_date,price_end_date,price_current_flag)
		 values (game_id,game_name,min_memory_size,is_online,max_no_players,details,price,price_start_date,price_end_date,price_current_flag);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_games_dim',start_time,'game_dim_scd2',rows_changed,'merge temp_games into game_dim, inserting records of new games and games with new prices and updating old records of games with changed prices');
	select CURRENT_TIMESTAMP into start_time;
	commit;


END;
$$ LANGUAGE plpgsql;



create or replace procedure dw.public.etl_users_dim() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	if (select count(*) from "public".users_dim_scd3) = 0 THEN
		raise EXCEPTION 'users_dim_scd3 is empty, dangerous situation in etl_users_dim, please investigate. aborting.';
	end if;
	
	
	truncate "temp".temp_users;
	truncate "temp".temp_udc;
	
	
	insert into "temp".temp_users
	select user_id,email_address,first_name,last_name,birth_date,sc.country_code,sc.country_name
	from "sa"."users" as su join "sa"."countries" as sc on (su.country_code = sc.country_code);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_users_dim',start_time,'temp_users',rows_changed,'insert SA.users joined SA.countries into temp_users');
	select CURRENT_TIMESTAMP into start_time;
	
	insert into "temp".temp_udc
	select tu.user_id,tu.email_address,tu.first_name,tu.last_name,tu.birth_date,tu.country_code,tu.country_name
				,null,null,null,null,tu.country_code,tu.country_name
	from "public".users_dim_scd3 as ud right join "temp".temp_users as tu on (ud.user_id = tu.user_id)
	where ud.user_id is null;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_users_dim',start_time,'temp_udc',rows_changed,'insert new user records into temp_udc');
	select CURRENT_TIMESTAMP into start_time;
	
	
	insert into "temp".temp_udc
	select ud.user_id,ud.email_address,ud.first_name,ud.last_name,ud.birth_date,ud.original_country_code,ud.original_country_name
				,CASE ud.original_effective_until is null and ud.current_country_code != tu.country_code
				  WHEN true THEN
						CURRENT_DATE
					ELSE
						ud.original_effective_until
					END 
				,case ud.current_country_code != tu.country_code
					when true THEN
						ud.current_country_code
					ELSE
						ud.previous_country_code
					END
				,case ud.current_country_code != tu.country_code
					when true THEN
						ud.current_country_name
					ELSE
						ud.previous_country_name
					END
				,case ud.current_country_code != tu.country_code
					when true THEN
						CURRENT_DATE
					ELSE
						ud.previous_effective_until
					END
				,case ud.current_country_code != tu.country_code
					when true THEN
						tu.country_code
					ELSE
						ud.current_country_code
					END				
				,case ud.current_country_code != tu.country_code
					when true THEN
						tu.country_name
					ELSE
						ud.current_country_name
					END							
	from "public".users_dim_scd3 as ud join "temp".temp_users as tu on (ud.user_id = tu.user_id);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_users_dim',start_time,'temp_udc',rows_changed,'insert old user records with updated countries into temp_udc');
	select CURRENT_TIMESTAMP into start_time;
	
	truncate users_dim_scd3;
	insert into users_dim_scd3 
	select user_id,email_address,first_name,last_name,birth_date
	,original_country_code,original_country_name,original_effective_until
	,previous_country_code,previous_country_name,previous_effective_until
	,current_country_code,current_country_name
	from "temp".temp_udc;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_users_dim',start_time,'users_dim_scd3',rows_changed,'isnert all user records from temp_udc into users_dim');
	select CURRENT_TIMESTAMP into start_time;
	commit;

END
$$ LANGUAGE plpgsql;


	

create or replace procedure dw.public.etl_fact_orders_transactional() as $$

declare
	max_date date;
	last_update date;
	start_time TIMESTAMP with time zone;
	rows_changed int8;

BEGIN	
	select CURRENT_TIMESTAMP into start_time;
	truncate "temp".temp_agg;
	truncate "temp".temp_og;
	select to_date(max(time_key)::varchar(8),'YYYYMMDD') from "public".fact_orders_transactional into last_update;
	select CURRENT_DATE - interval '1 day' into max_date;
	
	
	
	insert into "temp".temp_agg
	select order_id,null,min(game_price),max(game_price),null,null,count(game_id),null
	from "sa".order_games as og
	group by order_id;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_transactional',start_time,'temp_agg',rows_changed,'insert new order records (aggregated) after last_update up until yesterday into temp_agg');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	insert into "temp".temp_og
	select so.order_id,user_id,order_date,null,null,game_key,sog.game_price,sog.price_after_discount
	from "sa".orders as so join "sa".order_games as sog on (so.order_id = sog.order_id)
	join "public".game_dim_scd2 as gd on (sog.game_id = gd.game_id)
	where gd.price_current_flag and (order_date > last_update) and (order_date <= max_date);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_transactional',start_time,'temp_og',rows_changed,'insert new order joined game_dim records after last_update up until yesterday into temp_og');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	
	
	insert into "public".fact_orders_transactional
	select order_id,user_id,game_id,to_char(order_date, 'YYYYMMDD')::int,game_price,price_after_discount,cgp,egp,games_count
	from "temp".temp_og as t1 join "temp".temp_agg as t2 on (t2.id = t1.order_id);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_transactional',start_time,'fact_orders_transactional',rows_changed,'insert new order records from temp_agg joined temp_og into fact table');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
END
$$ LANGUAGE plpgsql;





create or replace procedure dw.public.etl_fact_orders_monthly() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
	loop_date date;
	end_date date;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	select to_date(max(time_key)::varchar(8),'YYYYMMDD') + interval '1 month' from "public"."fact_orders_periodic_monthly" into loop_date;
	select CURRENT_DATE into end_date;

	truncate "temp".temp_agg;
	truncate "temp".temp_og;
	
	insert into "temp".temp_og
	select o.order_id,user_id,order_date,order_status,coupon_code,game_id,game_price,price_after_discount FROM
	"sa".orders as o join "sa".order_games as og on (o.order_id = og.order_id);
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_monthly',start_time,'temp_og',rows_changed,'insert all orders from SA.order joined SA.order_games into temp_og');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	
	WHILE to_char(loop_date,'YYYYMM')::int < to_char(end_date,'YYYYMM')::int 
	LOOP
		insert into "temp".temp_agg
		select user_id,to_char(loop_date,'YYYYMM01')::int,min(game_price),max(game_price),avg(game_price),sum(game_price),count(game_id),count(distinct(og.order_id))
		from "temp".temp_og as og
		where to_char(loop_date,'YYYYMM')::int = to_char(order_date,'YYYYMM')::int
		group by user_id;
		commit;
		GET DIAGNOSTICS rows_changed = ROW_COUNT;
		call logger('etl_fact_orders_monthly',start_time,'temp_agg',rows_changed,'insert records of month ' || to_char(loop_date,'YYYY-MM') || ' into temp_agg');
		select CURRENT_TIMESTAMP into start_time;
		select loop_date + interval '1 month' into loop_date;
		commit;
	END LOOP;

	insert into "public".fact_orders_periodic_monthly 
	select id,time_key,cgp,egp,agp,tgp,number_of_orders,games_count
	from "temp".temp_agg;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_monthly',start_time,'fact_orders_periodic_monthly',rows_changed,'copy records from temp_agg to fact table');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
END
$$ LANGUAGE plpgsql;





create or replace procedure dw.public.etl_fact_orders_acc() as $$

declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;

BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	truncate "temp".temp_agg;
	truncate "public".fact_orders_acc;
	
	
	insert into "temp".temp_agg
	select u.user_id,null,min(cheapest_game_price),max(expensive_game_price),sum(total_game_price)/sum(total_games_bought),sum(total_game_price)
	,sum(total_games_bought),sum(number_of_orders)
	from "sa".users as u left join "public".fact_orders_periodic_monthly as opm on (u.user_id = opm.user_id)
	group by u.user_id;
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_acc',start_time,'temp_agg',rows_changed,'insert all records for each user into temp_agg');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	insert into "public".fact_orders_acc 
	select id,cgp,egp,agp,tgp,number_of_orders,games_count
	from "temp".temp_agg;
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('etl_fact_orders_acc',start_time,'fact_orders_acc',rows_changed,'insert all records from temp_agg into fact_orders_acc');
	select CURRENT_TIMESTAMP into start_time;
	commit;

END
$$ LANGUAGE plpgsql;




create or replace PROCEDURE dw.public.sa_to_dw_etl() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	
	create extension if not exists postgres_fdw;
	CREATE SERVER if not exists "sa_server"
	FOREIGN DATA WRAPPER postgres_fdw
	OPTIONS (host 'localhost', dbname 'sa', port '5432');
	drop user mapping IF EXISTS for "postgres" server "sa_server";
	create user mapping for "postgres" server "sa_server" options(user 'postgres', password '1234qwer');
	commit;
	
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'preparing source server connection');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	drop FOREIGN table if exists "sa"."orders";
	drop FOREIGN table if exists "sa"."order_games";
	drop FOREIGN table if exists "sa"."users";
	drop FOREIGN table if exists "sa"."countries";
	drop FOREIGN table if exists "sa"."games";
	drop FOREIGN table if exists "sa"."coupons";
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'dropped all source foreign tables');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	IMPORT FOREIGN SCHEMA "public" LIMIT TO (order_games,orders,users,countries,coupons,games)
    FROM SERVER "sa_server" INTO "sa";
	commit;
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'copying SA server tables into sa_server foreign schema');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	call dw.public.etl_orders_dim();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_orders_dim');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.etl_games_dim();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_games_dim');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.etl_users_dim();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_users_dim');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.etl_fact_orders_transactional();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_fact_orders_transactional');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.etl_fact_orders_monthly();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_fact_orders_monthly');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.etl_fact_orders_acc();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'called etl_fact_orders_acc');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
	
	
	drop FOREIGN table if exists "sa"."order_games";
	drop FOREIGN table if exists "sa"."orders";
	drop FOREIGN table if exists "sa"."users";
	drop FOREIGN table if exists "sa"."countries";
	drop FOREIGN table if exists "sa"."games";
	drop FOREIGN table if exists "sa"."coupons";
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('sa_to_dw_etl',start_time,null,rows_changed,'dropped all source foreign tables');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	
end;
$$ language plpgsql;



----------------------------
--- MAIN FL ETL PROCEDURE
----------------------------


create or replace procedure dw.public.ETL() as $$
declare 
	start_time TIMESTAMP with time zone;
	rows_changed int8;
BEGIN
	select CURRENT_TIMESTAMP into start_time;
	
	create extension if not exists dblink;
	
    begin     -- try 
				PERFORM dblink_disconnect('sa');
    exception -- catch 
			when OTHERS  then
				raise notice 'connection did not exist';
    end ; -- try..catch
	
	PERFORM dblink_connect('sa','dbname=sa user=postgres password=1234qwer');
	PERFORM dblink_exec('sa','call sa.public.source_to_sa_etl();');
	PERFORM dblink_disconnect('sa');
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('ETL',start_time,null,rows_changed,'called sa.public.source_to_sa_etl remotely');
	select CURRENT_TIMESTAMP into start_time;
	commit;
	
	call dw.public.sa_to_dw_etl();
	GET DIAGNOSTICS rows_changed = ROW_COUNT;
	call logger('ETL',start_time,null,rows_changed,'called dw.public.sa_to_dw_etl');
	select CURRENT_TIMESTAMP into start_time;
	commit;
end;
$$ language plpgsql;




call dw.public.ETL();


