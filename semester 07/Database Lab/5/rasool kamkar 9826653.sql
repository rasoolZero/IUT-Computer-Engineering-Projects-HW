--Q1
--SELECT P.Name, [GROUP],OrderQty
--FROM Sales.SalesOrderDetail AS OD JOIN Sales.SalesOrderHeader AS OH ON (OD.SalesOrderID = OH.SalesOrderID)
--JOIN Sales.SalesTerritory AS T ON (OH.TerritoryID = T.TerritoryID)
--JOIN Production.Product AS P ON (OD.ProductID = P.ProductID)

Select Name,[Europe],[North America],[Pacific] FROM 
(SELECT P.Name, [GROUP],OrderQty
FROM Sales.SalesOrderDetail AS OD JOIN Sales.SalesOrderHeader AS OH ON (OD.SalesOrderID = OH.SalesOrderID)
JOIN Sales.SalesTerritory AS T ON (OH.TerritoryID = T.TerritoryID)
JOIN Production.Product AS P ON (OD.ProductID = P.ProductID)) AS DS
PIVOT(
COUNT (OrderQty)
FOR [Group] IN (Europe,[North America] ,Pacific)
) as PVT;


--Q2
--SELECT Person.BusinessEntityID, PersonType, Gender
--FROM Person.Person JOIN HumanResources.Employee ON (Person.BusinessEntityID =
--Employee.BusinessEntityID);

SELECT PersonType,M,F FROM
(SELECT Person.BusinessEntityID, PersonType, Gender
FROM Person.Person JOIN HumanResources.Employee ON (Person.BusinessEntityID = Employee.BusinessEntityID)
) AS DS
PIVOT(
COUNT(BusinessEntityID)
FOR Gender IN (F,M)
) AS PVT

--Q3
SELECT Name From Production.Product
WHERE LEN(Name) < 15 AND LEFT(RIGHT(Name,2),1) = 'e'




--Q4
GO
CREATE FUNCTION dbo.DateConvert(@DateStr CHAR(10)) RETURNS NVARCHAR(200) AS
BEGIN
	DECLARE @ret NVARCHAR(200);
	IF (PATINDEX('[0-9][0-9][0-9][0-9]/[0-9][0-9]/[0-9][0-9]',@DateStr) = 0)
		SET @ret = N'فرمت تاریخ ناصحیح است';
	ELSE
	BEGIN
	DECLARE @YEAR CHAR(4);
	DECLARE @MONTH CHAR(2);
	DECLARE @monthName NVARCHAR(50);
	DECLARE @DAY CHAR(2);
	SET @YEAR = LEFT(@DateStr,4);
	SET @MONTH = RIGHT(LEFT(@DateStr,7),2);
	SET @DAY = RIGHT(@DateStr,2);
	SET @monthName = CASE @MONTH
		WHEN '01' THEN N'فروردین'
		WHEN '02' THEN N'اردبیهشت'
		WHEN '03' THEN N'خرداد'
		WHEN '04' THEN N'تیر'
		WHEN '05' THEN N'مرداد'
		WHEN '06' THEN N'شهریور'
		WHEN '07' THEN N'مهر'
		WHEN '08' THEN N'آبان'
		WHEN '09' THEN N'آذر'
		WHEN '10' THEN N'دی'
		WHEN '11' THEN N'بهمن'
		WHEN '12' THEN N'اسفند'
	END
	--SET @ret = CONCAT(N'شمسی ',@year,N' ماه ',@MONTH,' ',@DAY);
	SET @ret = CONCAT(N'تاریخ ',@DAY,' ',@monthName,N' ماه ',@year,N' شمسی');
	END
	RETURN @ret;
END;

GO 
SELECT dbo.DateConvert('1234/12/12'),dbo.DateConvert('123/01/02'),dbo.DateConvert('1234/2/1');


--Q5
GO
CREATE FUNCTION dbo.TerritoryFromDateProduct(@YEAR INT,@MONTH INT,@ProductName NVARCHAR(50)) RETURNS TABLE AS RETURN
(SELECT DISTINCT(T.Name) FROM
Sales.SalesOrderHeader as OH JOIN Sales.SalesOrderDetail as OD ON (OH.SalesOrderID = OD.SalesOrderID)
JOIN Production.Product as P ON (OD.ProductID = P.ProductID)
JOIN Sales.SalesTerritory as T ON (OH.TerritoryID = T.TerritoryID)
WHERE MONTH(OrderDate) = @MONTH AND
YEAR(OrderDate) = @YEAR AND
P.Name = @ProductName
);

GO
SELECT * FROM TerritoryFromDateProduct(2006,5,'Sport-100 Helmet, Red');

--SELECT T.Name,OrderDate,P.Name FROM
--Sales.SalesOrderHeader as OH JOIN Sales.SalesOrderDetail as OD ON (OH.SalesOrderID = OD.SalesOrderID)
--JOIN Production.Product as P ON (OD.ProductID = P.ProductID)
--JOIN Sales.SalesTerritory as T ON (OH.TerritoryID = T.TerritoryID)
--WHERE MONTH(OrderDate) = 5 AND
--YEAR(OrderDate) = 2006 AND
--P.Name = 'Sport-100 Helmet, Red';