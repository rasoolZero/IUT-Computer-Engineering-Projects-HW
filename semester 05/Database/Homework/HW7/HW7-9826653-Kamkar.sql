---- DATABASE DESIGN 1 @ IUT
---- YOUR NAME:
---- YOUR STUDENT NUMBER: 


---- Q1
---A
alter table rental add column customer_rate
numeric(3,0) DEFAULT 50
check(customer_rate >= 0 and customer_rate <= 100);

alter table film add column score numeric(3,2);


---B
CREATE OR REPLACE FUNCTION update_film_score() RETURNS trigger AS $$
			declare f_id int;
			declare customer_rate_sum int;
			declare rent_total int;
    BEGIN
				select (film_id into f_id) from rental,inventory 
				where rental.rental_id = NEW.rental_id and rental.inventory_id = inventory.inventory_id;
				
				select (sum(customer_rate) into customer_rate_sum) from rental,inventory 
				where rental.inventory_id = inventory.inventory_id and inventory.film_id = f_id;
				
				select (count(*) into rent_total) from rental,inventory 
				where rental.inventory_id = inventory.inventory_id and inventory.film_id = f_id;
				
				update film set score = customer_rate_sum / rent_total where film_id = f_id;
        RETURN NULL;
    END;
$$ LANGUAGE plpgsql;


create trigger update_score
after update of customer_rate on rental
for each row
execute procedure update_film_score();


---C
select rental_id,film_id,customer_rate from rental,inventory 
where rental.inventory_id = inventory.inventory_id and inventory.film_id = 2;
select film_id, score from film where film_id = 2;
update rental set customer_rate = 69 where rental_id = 4364;
select rental_id,film_id,customer_rate from rental,inventory 
where rental.inventory_id = inventory.inventory_id and inventory.film_id = 2;
select film_id, score from film where film_id = 2;



---- Q3
---A
alter table customer add column rent_count int default 0;

CREATE OR REPLACE FUNCTION free_film() RETURNS trigger AS $$
    
		BEGIN
				if (select rent_count from customer where customer_id = NEW.customer_id) < 4 then
					update customer set rent_count = rent_count+1 where customer_id = NEW.customer_id;
					return NULL;	
				end if;
		
				with all_rented_movies as(
				select * from rental join inventory using(inventory_id) join film using(film_id) where rental.customer_id = NEW.customer_id)
				,categories as(
				select category_id from film_category where film_id in (select film_id from all_rented_movies order by rental_date desc limit 5))
				,last_order_store_id as (
					select distinct(store_id) as store_id from staff where staff_id = NEW.staff_id) 
				,all_suitable_movies as(select distinct(film.film_id) from film,film_category,inventory where film.film_id = film_category.film_id and film.film_id = inventory.film_id
				and film_category.category_id in (select * from categories)
				and film.film_id not in (select film_id from all_rented_movies)
				and inventory.store_id = (select store_id from last_order_store_id))
				, random_number as (
					select floor(random() * (select count(*) from all_suitable_movies))
				)
				, selected_movie as (select * from all_suitable_movies offset (select * from random_number) limit (1))
				
				insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) 
				values(NOW(),
				(select inventory_id from inventory where store_id = (select store_id from last_order_store_id) and film_id = (select * from selected_movie) limit 1),
				NEW.customer_id,
				NULL,
				NEW.staff_id,
				NOW()
				);
				update customer set rent_count = 0 where customer_id = NEW.customer_id;
        RETURN NULL;
    END;
$$ LANGUAGE plpgsql;

create trigger free_film_trigger
after insert on rental
for each row
WHEN (pg_trigger_depth() = 0)
execute procedure free_film();


---B
select rent_count from customer where customer_id = 1;
insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) values(NOW(),170,1,NULL,1,NOW());
insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) values(NOW(),174,1,NULL,1,NOW());
insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) values(NOW(),189,1,NULL,1,NOW());
insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) values(NOW(),196,1,NULL,1,NOW());
select rent_count from customer where customer_id = 1;
insert into rental(rental_date,inventory_id,customer_id,return_date,staff_id,last_update) values(NOW(),201,1,NULL,1,NOW());
select rent_count from customer where customer_id = 1;
select rental_id,film_id,category_id,rental_date from rental join inventory using(inventory_id) join film using (film_id) join film_category using(film_id) where customer_id = 1 order by rental_date desc;

---- Q4
with sum_amounts as (
	select film_id,sum(amount) as sum_amount from payment join rental using(rental_id) join inventory using(inventory_id)
	group by film_id
)
select title as film_title,rating as film_rating,
rank() over (order by sum_amount desc) as rank_in_all,
rank() over (partition by rating order by sum_amount desc) as rank_in_rating,
sum_amount,
case
	when ntile(4) over (order by sum_amount desc) = 1 then 'Yes'
	else 'No'
end
as is_in_first_quartile
from film join sum_amounts using(film_id)
order by film_title;



---- Q5
select extract(month from payment_date) as month_number,rating,
sum(amount) as sum_amount,
lag(sum(amount),1) over (partition by rating order by extract(month from payment_date)) as prev_month_sales,
lead(sum(amount),1) over (partition by rating order by extract(month from payment_date)) as next_month_sales
from payment join rental using(rental_id) join inventory using(inventory_id) join film using(film_id)
group by month_number,rating
order by month_number,rating;



---- Q6
---A
select film.film_id,staff.staff_id,store.store_id,address.city_id,
count(rental.rental_id) as total_rent
from rental, staff, inventory,film,store,address
where rental.inventory_id = inventory.inventory_id and
inventory.film_id = film.film_id and
rental.staff_id = staff.staff_id and
staff.store_id = store.store_id and
store.address_id = address.address_id
group by cube(store.store_id,staff.staff_id,film.film_id,address.city_id)
order by total_rent desc;



---B
select film.film_id,staff.staff_id,store.store_id,address.city_id,
count(rental.rental_id) as total_rent
from rental, staff, inventory,film,store,address
where rental.inventory_id = inventory.inventory_id and
inventory.film_id = film.film_id and
rental.staff_id = staff.staff_id and
staff.store_id = store.store_id and
store.address_id = address.address_id
group by grouping sets (
()
,(store.store_id)
,(staff.staff_id)
,(film.film_id)
,(address.city_id)
,(store.store_id, staff.staff_id)
,(store.store_id, film.film_id)
,(store.store_id, address.city_id)
,(staff.staff_id, film.film_id)
,(staff.staff_id, address.city_id)
,(film.film_id, address.city_id)
,(store.store_id, staff.staff_id, film.film_id)
,(store.store_id, staff.staff_id, address.city_id)
,(store.store_id, film.film_id, address.city_id)
,(staff.staff_id, film.film_id, address.city_id)
,(store.store_id, staff.staff_id, film.film_id, address.city_id)
)
order by total_rent desc;



















