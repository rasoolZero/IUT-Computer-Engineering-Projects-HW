--Q1
go
create Trigger SaveDelete
on Production.Product
For Delete
AS
begin
--
insert into Production.ProductLogs select 'Delete',* from deleted
end;

go
Create Trigger SaveInsert
on Production.Product
For Insert
AS
begin
--
insert into Production.ProductLogs select 'Insert',* from inserted
end;


go
Create Trigger SaveUpdate
on Production.Product
For Update
AS
begin
--
insert into Production.ProductLogs select 'Before Update',* from deleted
insert into Production.ProductLogs select 'After Update',* from inserted
end;

--Q1 test
update Production.Product set Name = 'a new name' where ProductID = 1;
update Production.Product set Name = 'new name for product 3' where ProductID = 3;
--delete from Production.Product where ProductID = 2;


--Q2
select * into Production.ProductLogsCopy from Production.ProductLogs;
select * from Production.ProductLogsCopy;
update Production.ProductLogsCopy set Name = 'new name for product 1' where ProductID = 1 and LogType = 'After Update';
select * from Production.ProductLogsCopy;

--Q3
go
create procedure Production.Diff as
with temp as (select * from Production.ProductLogs
except
select * from Production.ProductLogsCopy
)
select * into Production.ProductLogsDiff from temp;

--Q3 test
exec Production.Diff;