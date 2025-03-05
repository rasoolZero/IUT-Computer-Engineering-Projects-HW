create or replace procedure clean_data()
language SQL
AS $$
	with cleaned_data as (
		select * from "sales_details1" as sd1
		where not ((day_jalali > 30 and month_jalali > 6)
		or (day_jalali > 29 and month_jalali = 12 and year_jalali != 1399))
		group by  sd1.invoice_number, sd1.branch_id, sd1.product_id, sd1.units_sold, sd1.year_jalali, sd1.month_jalali, sd1.day_jalali 
	)
	
	select * into "sales_details2" from cleaned_data;
$$;

call clean_data()





create or replace procedure branch_product_units_sold_remove_outlier()
language plpgsql
as $$
	begin
	
		-- part one : create a temp table containing sum of units sold for each branch and each product in each day
		CREATE TABLE IF NOT EXISTS sales_details3_temp AS
		select branch_id,product_id,day_jalali,month_jalali,year_jalali, sum(units_sold) as sum_units_sold
		from "sales_details2"
		group by branch_id,product_id,day_jalali,month_jalali,year_jalali;
		COMMIT;
		
		-- part two : create a temp table containing Q1, Q3, IQR, lower boundry, upper boundry and avg units sold
		-- for each branch and each product
		
		CREATE TABLE IF NOT EXISTS utils_temp AS
		with quartiles as (
			select branch_id,product_id, sum_units_sold,
			ntile(4) over (partition by branch_id, product_id order by sum_units_sold)
			from "sales_details3_temp"
		)
		,Q1 as (	
			select branch_id, product_id, max(sum_units_sold) as units_q1
			from quartiles where ntile = 1
			group by branch_id,product_id
		)
		,Q3 as (	
			select branch_id, product_id, max(sum_units_sold) as units_q3
			from quartiles where ntile = 3
			group by branch_id,product_id
		)
		, avg_units_sold as (
			select branch_id, product_id, avg(units_sold) as avg_units_sold
			from sales_details2
			group by branch_id, product_id
		)
		select Q1.branch_id, Q1.product_id,
					(units_q3 + (units_q3 - units_q1) * 1.5) as upper_boundry,
					(units_q1 - (units_q3 - units_q1) * 1.5) as lower_boundry,
					avg_units_sold
		from  Q1 join Q3
		on (Q1.branch_id = Q3.branch_id
				and Q1.product_id = Q3.product_id)
		join avg_units_sold as av
		on (Q1.branch_id = av.branch_id
				and Q1.product_id = av.product_id)
		order by Q1.branch_id, Q1.product_id;
		COMMIT;
		
		-- part three : creating the main sales_details3 table using condition on units sold and lower boundy | upper boundry
		
		CREATE TABLE IF NOT EXISTS sales_details3 AS
		select t1.branch_id, t1.product_id, t1.day_jalali, t1.month_jalali, t1.year_jalali,
			case 
				when sum_units_sold <= lower_boundry or sum_units_sold >= upper_boundry then avg_units_sold
				else sum_units_sold
			end as units_sold
		from sales_details3_temp as t1 join utils_temp as t2
		on (t1.branch_id = t2.branch_id
				and t1.product_id = t2.product_id);
		COMMIT;
		
		-- part four : remove temp tables
		drop table sales_details3_temp;
		drop table utils_temp;
		COMMIT;
		
	end;
$$;

call branch_product_units_sold_remove_outlier();





