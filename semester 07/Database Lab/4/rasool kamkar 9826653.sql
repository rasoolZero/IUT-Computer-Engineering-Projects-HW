USE AdventureWorks2012
GO
SELECT Sales.SalesOrderHeader.OrderDate, Sales.SalesOrderDetail.LineTotal,
AVG(Sales.SalesOrderDetail.LineTotal)OVER (PARTITION BY Sales.SalesOrderHeader.CustomerID
ORDER BY Sales.SalesOrderHeader.OrderDate, Sales.SalesOrderHeader .SalesOrderID
ROWS BETWEEN 2 PRECEDING AND CURRENT ROW)
FROM Sales.SalesOrderHeader JOIN Sales.SalesOrderDetail ON
(SalesOrderDetail.SalesOrderID = SalesOrderHeader.SalesOrderID);

USE AdventureWorks2012
GO
SELECT 
case grouping(SalesTerritory.Name) 
	when 0 then Name
	when 1 then 'All Territories'
end as TerritoryName,
case grouping(SalesTerritory.[Group]) 
	when 0 then [Group]
	when 1 then 'All Regions'
end AS Region
, SUM (SalesOrderHeader.SubTotal) as SalesTotal, Count(SalesOrderID) as SalesCount 
FROM Sales.SalesTerritory JOIN Sales.SalesOrderHeader ON (SalesTerritory.TerritoryID = SalesOrderHeader.TerritoryID)
Group By Rollup(SalesTerritory.[Group],SalesTerritory.Name);

USE AdventureWorks2012
GO
select 
ProductSubcategory.ProductSubcategoryID,ProductSubcategory.ProductCategoryID
, Count (SalesOrderHeader.SalesOrderID) as SalesCount
, SUM (SubTotal) as SalesTotal
from Sales.SalesOrderHeader join Sales.SalesOrderDetail ON (SalesOrderHeader.SalesOrderID = SalesOrderDetail.SalesOrderID)
JOIN Production.Product ON (Product.ProductID = SalesOrderDetail.ProductID)
JOIN Production.ProductSubcategory ON (Product.ProductSubcategoryID = ProductSubcategory.ProductSubcategoryID)
JOIN Production.ProductCategory ON (ProductSubcategory.ProductCategoryID = ProductCategory.ProductCategoryID)
group by rollup (ProductSubcategory.ProductCategoryID,ProductSubcategory.ProductSubcategoryID)
order by ProductSubcategoryID desc;