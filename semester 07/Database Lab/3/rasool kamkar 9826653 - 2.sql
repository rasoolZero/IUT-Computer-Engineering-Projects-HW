use AdventureWorks2012;

create table mytable
(
	id char(10) not null primary key,
	firstname varchar(50),
	lastname varchar(50),
	email varchar(100) unique
);

insert into mytable values('1','ali','bagheri','alibagehri98@yahoo.com');
insert into mytable values('2','mohammad yasin','karimi','MYKarimi@gmail.com');

select * from mytable;