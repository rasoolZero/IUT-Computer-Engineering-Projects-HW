---- DATABASE DESIGN 1 @ IUT
---- YOUR NAME: Rasool Kamkar
---- YOUR STUDENT NUMBER: 9826653


---- Q7
---A
alter table student add gpa decimal;
---B
with takes_credits as (
	select id,takes.course_id,credits,grade, (
		case
			when grade like 'A%' then 4
			when grade like 'B%' then 3
			when grade = 'C+' then 2
			when grade = 'C-' then 0
			else 1
		end
	) as score
	from takes,course where takes.course_id = course.course_id
)

update student S set gpa = (	
	select sum(credits*score)/sum(credits)
	from takes_credits,student as S2
	where S2.id = S.id and takes_credits.id = S.id
	group by S2.id
);