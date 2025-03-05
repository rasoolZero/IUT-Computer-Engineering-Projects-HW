select Sales.SalesOrderHeader.* , Sales.SalesTerritory.Name as 'Territory Name' , Sales.SalesTerritory.[Group]
from Sales.SalesOrderHeader JOIN Sales.SalesTerritory 
on (SalesOrderHeader.TerritoryID = SalesTerritory.TerritoryID)
where TotalDue >= 100000 and TotalDue <= 500000 and (CountryRegionCode = 'FR' or [Group] = 'North America' );


Select SalesOrderID,CustomerID,TotalDue,OrderDate,SalesTerritory.Name as 'Territory Name'
FROM Sales.SalesOrderHeader JOIN Sales.SalesTerritory on (SalesTerritory.TerritoryID = SalesOrderHeader.TerritoryID);


select Sales.SalesOrderHeader.* , Sales.SalesTerritory.Name as 'Territory Name' , Sales.SalesTerritory.[Group]
Into NAmerica_Sales
from Sales.SalesOrderHeader JOIN Sales.SalesTerritory 
on (SalesOrderHeader.TerritoryID = SalesTerritory.TerritoryID)
where TotalDue >= 100000 and TotalDue <= 500000 and  [Group] = 'North America';


alter table NAmerica_Sales add compare_avg char(4);

with NA_avg as (select avg(TotalDue) as avgs from NAmerica_Sales)
update NAmerica_Sales set [compare_avg] = 
(case 
	when NAmerica_Sales.TotalDue < (select NA_avg.avgs from NA_avg) then 'Low'
	when NAmerica_Sales.TotalDue > (select NA_avg.avgs from NA_avg) then 'High'
	else 'Mid'
end);


with salary_tiles as (select BusinessEntityID as BID, ntile(4) over (ORDER BY MAX(rate) ASC) as rate_tile from HumanResources.EmployeePayHistory group by BusinessEntityID )
SELECT BusinessEntityID,
case
	when rate_tile = 1 then Rate + Rate*0.20
	when rate_tile = 2 then Rate + Rate*0.15
	when Rate_tile = 3 then Rate + Rate*0.10
	else Rate + Rate*0.5
end as new_salary,
case 
	when Rate <=29 then 1
	when Rate <=59 then 2
	else 3
end as Level
FROM HumanResources.EmployeePayHistory join salary_tiles on (BusinessEntityID = salary_tiles.BID)