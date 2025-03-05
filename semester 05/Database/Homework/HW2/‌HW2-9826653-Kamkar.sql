---- DATABASE DESIGN 1 @ IUT
---- YOUR NAME:Rasool Kamkar
---- YOUR STUDENT NUMBER: 9826653


---- Q4-A
SELECT film.title,film."length" FROM film,film_category,category
WHERE film.film_id = film_category.film_id AND
film_category.category_id = category.category_id AND
category."name" = 'Action' AND film.title LIKE 'C%'
ORDER BY film."length" DESC;

---- Q4-B
SELECT film.title,lang."name" as "language" FROM film,"language" AS lang
WHERE film.language_id = lang.language_id AND
film.rental_rate > (SELECT AVG(rental_rate) FROM film)
ORDER BY film.rental_rate DESC
LIMIT 5;

---- Q4-C
SELECT customer.customer_id FROM customer,rental,inventory,film,film_actor,actor
WHERE customer.customer_id = rental.customer_id AND
rental.inventory_id = inventory.inventory_id AND
inventory.film_id = film.film_id AND
film.film_id = film_actor.film_id AND
film_actor.actor_id = actor.actor_id AND
actor.actor_id = 152
GROUP BY customer.customer_id
HAVING COUNT(film.film_id) >= 3;

---- Q4-D
SELECT address.address,SUM(payment.amount) AS total_amount FROM store,address,staff,payment
WHERE store.address_id = address.address_id AND
store.store_id = staff.store_id AND
staff.staff_id = payment.staff_id
GROUP BY address.address
ORDER BY total_amount
LIMIT 1;

---- Q4-E
SELECT film.rating,COUNT(DISTINCT film.film_id) FROM film,inventory,rental WHERE
film.film_id = inventory.film_id AND
inventory.inventory_id = rental.inventory_id
GROUP BY film.rating;

---- Q4-F
SELECT CAT."name",
(
	SELECT film.title FROM film,film_category
	WHERE film.film_id = film_category.film_id AND
	film_category.category_id = CAT.category_id
	ORDER BY film."length" DESC LIMIT 1
) AS "longest_film",
(
	SELECT film.title FROM film,film_category
	WHERE film.film_id = film_category.film_id AND
	film_category.category_id = CAT.category_id
	ORDER BY film.rental_rate DESC LIMIT 1
) AS "most_rental_rate"
FROM category AS CAT;














---- Q5-A
SELECT student."id",student."name" FROM student WHERE
student."name" LIKE 'M%a';

---- Q5-B
SELECT course.title FROM course,"section" WHERE
course.course_id = "section".course_id AND
semester = 'Fall' AND "year" = 2009 AND
course.dept_name LIKE '%Eng.';

---- Q5-C
SELECT student."name",course.title FROM student,takes,course WHERE
student."id" = takes."id" AND
takes.course_id = course.course_id
GROUP BY student."id",course.course_id
HAVING COUNT(course.course_id) >=3;

---- Q5-D
SELECT prereq_id AS course_id,SUM(credits) AS total_credits FROM prereq,course WHERE
course.course_id = prereq.course_id
GROUP BY prereq_id
HAVING SUM(credits) > 4
ORDER BY total_credits DESC;

---- Q5-E
SELECT concat(classroom.building,' ',classroom.room_number) AS classroom_number
FROM classroom,"section",time_slot WHERE
(classroom.building,classroom.room_number) = ("section".building,"section".room_number) AND
"section".time_slot_id = time_slot.time_slot_id AND
"section"."year"=2008 AND "section".semester='Spring'
GROUP BY classroom_number
HAVING SUM(time_slot.end_hr-time_slot.start_hr) >= 2;

---- Q5-F
SELECT instructor."name", COUNT(course_id) FROM instructor, teaches WHERE
instructor."id" = teaches."id" AND
teaches."year" = 2003
GROUP BY instructor."id"
HAVING COUNT(course_id) < (
	SELECT AVG("c") FROM (SELECT COUNT(course_id) AS "c" FROM instructor, teaches WHERE
	instructor."id" = teaches."id" AND
	teaches."year" = 2003
	GROUP BY instructor."id") AS "avg"
);

---- Q5-G
SELECT DISTINCT(course.course_id),course.title FROM "section",time_slot,course WHERE
"section".time_slot_id = time_slot.time_slot_id AND
"section".course_id = course.course_id AND
"section".building = 'Taylor' AND "section"."year" = 2007 AND
time_slot.start_hr BETWEEN 8 AND 12;

---- Q5-H
SELECT student."name",SUM(course.credits) as total_credits FROM student,takes,course WHERE
student."id" = takes."id" AND
takes.course_id = course.course_id AND
(takes.grade LIKE 'B%' OR takes.grade LIKE 'A%')
GROUP BY student."id";
