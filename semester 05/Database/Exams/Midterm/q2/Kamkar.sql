--2A


--2B
select category_id,avg(rental.return_date - rental.rental_date) from film_category,film,inventory,rental
where film_category.film_id = film.film_id AND
film.film_id = inventory.film_id AND
inventory.inventory_id = rental.inventory_id
group by category_id;


--2C
with top_seven as (
	select film.film_id,count(*) from film,inventory,rental
	where film.film_id = inventory.film_id AND
	inventory.inventory_id = rental.inventory_id
	group by film.film_id
	order by count desc
	limit 7)

select distinct(actor_id),first_name from actor inner join film_actor using(actor_id)
where film_id in (select film_id from top_seven)
order by first_name;


--2D
create view _view as (
select title,
(select count(*) from inventory inner join rental using(inventory_id) where inventory.film_id = F1.film_id) as rental_count,
(select avg(rental.return_date - rental.rental_date) from inventory inner join rental using(inventory_id) where inventory.film_id = F1.film_id) as avg_rent_time,
(select count(*) from film_actor where film_id = F1.film_id) as actors_count
from film as F1);

select * from _view order by title;

