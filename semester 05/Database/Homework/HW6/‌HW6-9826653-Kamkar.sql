---- DATABASE DESIGN 1 @ IUT Homework6
---- YOUR NAME: Rasool Kamkar
---- YOUR STUDENT NUMBER: 9826653


---- Q1
create table trader(
	trader_id int PRIMARY KEY,
	trader_name varchar(100),
	birth_date DATE,
	joined_date DATE,
	salary numeric(8,2),
	check (salary > 1000 and birth_date >= '1900-01-01' and joined_date > birth_date)
);

insert into trader values(0,'Alex','2000-01-01','1999-01-01',2000);



---- Q2
create function is_early(time_id varchar(4)) returns boolean language plpgsql
as
$$
declare function_output boolean;
begin
	select (time_id in (select time_slot_id from time_Slot where time_slot.start_hr < 9)) into function_output;
	return function_output;
end;
$$;

alter table "section"
add check (is_early(time_slot_id));



---- Q3
select (customer.first_name || ' ' || customer.last_name) as customer_fullname, film.title
from customer,rental,inventory,film,payment where
customer.customer_id = rental.customer_id and rental.inventory_id = inventory.inventory_id and
inventory.film_id = film.film_id and rental.rental_id = payment.rental_id and
(payment.payment_date - (interval '1 year' +interval '3 months' +interval '15 days')) - rental.return_date > '0 day';



---- Q5
explain select * from film where title = 'Chamber Italian';

create index film_title on film(title);
explain select * from film where title = 'Chamber Italian';



---- Q6
SELECT tablename, indexname, indexdef
FROM pg_indexes WHERE schemaname = 'sales';



---- Q7

---A
create role role1;
grant select on instructor to role1 with grant option;


---B
create role role2;
grant role1 to role2;
grant update,delete,insert on course,student to role2;


---C
create role role3;
grant update (dept_name) on student to role3;
revoke all PRIVILEGES on student from role3;



---D	
create view elec_and_comp_students as
(
	select student.id as student_id,"name",student.dept_name as student_department,takes.course_id,title as course_title,
	semester,year,grade from student,takes, course
	where student."id"= takes."id" and takes.course_id = course.course_id and
	student.dept_name in ('Elec. Eng.','Comp. Sci.')
);

create role role4;
grant select on elec_and_comp_students to role4;

	
	
	
---- Q8


---A
create table accounts (
	account_id SERIAL,
	name varchar(150),
	balance numeric(12,3),
	PRIMARY key (account_id)
);
insert into accounts (name,balance) values('Amir',1000);


---B
insert into accounts (name,balance) values('Ali',2000);

begin transaction;
update accounts set balance = balance - 200 where "name" = 'Amir';
update accounts set balance = balance + 200 where "name" = 'Ali';
commit;
rollback;


---C
begin transaction;
update accounts set balance = balance - 150 where "name" = 'Ali';
update accounts set balance = balance + 150 where "name" = 'Amir';
rollback;



---Q9
create function get_customers(district_name varchar(20)) 
returns table (first_name varchar(45),title varchar(255)) language plpgsql as
$$
begin
return query select customer.first_name,
(
	select film.title from film,inventory,rental where
	rental.customer_id = customer.customer_id and
	rental.inventory_id = inventory.inventory_id and
	inventory.film_id = film.film_id order by rental.rental_date DESC limit 1
)
from address,customer
where customer.address_id = address.address_id and district = district_name;
end;
$$;

SELECT * FROM get_customers('Alberta');
SELECT * FROM get_customers('England');




---Q10
create PROCEDURE change_ratings(film1 varchar(255),film2 varchar(255))
language plpgsql as $$
declare first_rating mpaa_rating;
declare second_rating mpaa_rating;
begin
	--get ratings;
	select rating into first_rating from film where title = film1;
	 select rating into second_rating from film where title = film2;
	--update ratings
	update film set rating = first_rating where title = film2;
	update film set rating = second_rating where title = film1;
commit;
end; $$;

call change_ratings('Chamber Italian','Airport Pollock');
select title,rating from film where title in ('Chamber Italian','Airport Pollock');










