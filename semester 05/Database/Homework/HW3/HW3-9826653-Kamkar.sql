---- DATABASE DESIGN 1 @ IUT
---- YOUR NAME: Rasool Kamkar
---- YOUR STUDENT NUMBER: 9826653


---- Q1
---A
select instructor.dept_name
from instructor
group by dept_name
having sum(salary) >= (
	select avg(dept_total.s) from(
		select sum(salary) as s
		from instructor
		group by dept_name )as dept_total
);

---B
with teach_count (name,value) as (
	select instructor."name",count(*)
	from teaches, instructor
	where teaches.id = instructor.id and "year"=2003
	group by instructor.id),
avg_teach_count (value) as(
	select avg(teach_count.value) from teach_count
) 
select "name",teach_count."value" as "count"
from teach_count,avg_teach_count
where teach_count.value>avg_teach_count.value;


---- Q2
---A
create table uni_data (
	stu_id varchar(5),
	‌stu_name varchar(20),
	stu_dept_name varchar(20),
	‌year numeric(4,0),
	semester varchar(6),
	course_name varchar(50),
	score numeric(3,0),
	is_rank numeric(1,0)
);

---B
insert into uni_data(
	select student.id,student."name",student.dept_name,takes."year",takes.semester,course.title,(
		case
			when takes.grade = 'A+' then 100
			when takes.grade = 'A ' then 95
			when takes.grade = 'A-' then 90
			when takes.grade = 'B+' then 85
			when takes.grade = 'B ' then 80
			when takes.grade = 'B-' then 75
			when takes.grade = 'C+' then 70
			when takes.grade = 'C ' then 65
			when takes.grade = 'C-' then 60
			else 0
		end),
	(case
			when takes.grade like 'A%' or takes.grade like 'B%' then 1
			else 0
		end)
	from student,takes,course
	where student."id"=takes."id" and
	takes.course_id=course.course_id
);

---C
update uni_data
set score = (
		case
		when score < 75 then score+10
		else score+15
		end
	)
where uni_data.stu_dept_name = 'Physics';

---D
delete from uni_data as U1
where U1."‌stu_name" like 'T%' and
U1.score < (
	select avg(U2.score)
	from uni_data as U2
	where U2.stu_dept_name = U1.stu_dept_name
);


---- Q4
---A
select cs.course_id,title,dept_name,credits,sec_id,semester,year,building,room_number,time_slot_id from course as cs,"section" as se
where cs.course_id = "se".course_id
union
select * ,null,null,null,null,null,null from course
where course_id not in (select course.course_id from course,"section" where course.course_id = "section".course_id);

---B
select cs.course_id,title,dept_name,credits,sec_id,semester,year,building,room_number,time_slot_id from course as cs,"section" as se
where cs.course_id = "se".course_id
union
select course_id,null,null,null,sec_id,semester,"year",building,room_number,time_slot_id from "section"
where course_id not in (select course.course_id from course,"section" where course.course_id = "section".course_id);

---C
select cs.course_id,title,dept_name,credits,sec_id,semester,year,building,room_number,time_slot_id from course as cs,"section" as se
where cs.course_id = "se".course_id
union
select * ,null,null,null,null,null,null from course
where course_id not in (select course.course_id from course,"section" where course.course_id = "section".course_id)
union
select course_id,null,null,null,sec_id,semester,"year",building,room_number,time_slot_id from "section"
where course_id not in (select course.course_id from course,"section" where course.course_id = "section".course_id);




---- Q5
---A
select product.name,salesorderdetail.salesorderid from
production.product left join sales.salesorderdetail using(productid);

---B
select product.name from
production.product left join sales.salesorderdetail using(productid)
where salesorderdetail.salesorderid is null;
---C
select salesorderheader.customerid,product.name from
sales.salesorderheader inner join sales.salesorderdetail using(salesorderid)
inner join production.product using(productid);

---D
select customer.customerid,salesterritory.name,salesorderheader.salesorderid from
sales.salesorderheader right join (sales.customer inner join sales.salesterritory using(territoryid)) using (customerid);


---- Q6
create view subcategory_quantity as(
with workorders1000 as (select * from production.workorder
order by workorder.enddate desc limit 1000)
select prosub.productsubcategoryid as subcategory_id,prosub.name as subcategory_name, sum(orderqty) as sum_product_quantity
from workorders1000 inner join production.product using (productid)
inner join production.productsubcategory as prosub using(productsubcategoryid)
where workorders1000.workorderid not in (select distinct(workorderid) from production.workorderrouting where operationsequence = 7)
group by prosub.productsubcategoryid
order by sum_product_quantity desc);

---- Q7
create view stu_ins(id,name,dept_type,person_type) as(
select id,name,(case when dept_name like '%Eng%' then 'Engineer‌' else 'Scientist‌' end),'STU' from student
union
select id,name,(case when dept_name like '%Eng%' then 'Engineer‌' else 'Scientist‌' end),'INS' from instructor);

---- Q8
select stu_ins.name,person_type,
budget/(select count(*) from student where dept_name=department.dept_name) as ‌calc_number‌‌‌
from stu_ins inner join student using(id)
inner join department using (dept_name)
where stu_ins.person_type='STU'
union
select stu_ins.name,person_type, salary/budget*100
from stu_ins inner join instructor using(id)
inner join department using (dept_name)
where stu_ins.person_type='INS'

