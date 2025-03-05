use AdventureWorks2012
go
--create user loginCode for login loginCode

--grant select 
--on Sales.SalesOrderHeader
--to loginCode

--deny select
--on Sales.SalesOrderHeader
--to loginCode

--grant select
--on schema :: Sales
--to loginCode

--revoke select 
--on Sales.SalesOrderHeader
--to loginCode

--create role role2

--grant select
--on schema :: Person
--to role2

--alter role role2 add member loginCode

--grant select
--on database :: AdventureWorks2012
--to loginCode