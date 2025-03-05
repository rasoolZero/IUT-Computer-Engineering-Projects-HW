--- Q2
--- Dirty Read
use AdventureWorks2012
go
begin tran;
update Production.Product set name = 'Adjusting Racer' where ProductID = 1;
waitfor delay '00:00:30';
rollback;
--- run the next part in the delay
use AdventureWorks2012
go
begin tran;
SET TRANSACTION ISOLATION LEVEL READ UNCOMMITTED;
select name from Production.Product where ProductID = 1;
commit;





--- non-repeatable read
use AdventureWorks2012
go
begin tran;
select name from Production.Product where ProductID = 1;
waitfor delay '00:00:30';
select name from Production.Product where ProductID = 1;
commit;
--- run the next part in the delay
use AdventureWorks2012
go
begin tran;
update Production.Product set name = 'Adjusting Racer' where ProductID = 1;
commit;