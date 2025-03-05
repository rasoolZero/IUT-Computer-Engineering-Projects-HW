
create or replace procedure updateCustomerDimension() as $$
BEGIN

	truncate temp_customersdim_2;
	truncate temp_customersdim_1;
	truncate temp_customersdim_final;
	commit;
	
	insert into temp_customersdim_1
	select customerid,customername,branchid,ct.customertype,ct.customertypedescription,nationalid,phonenumber,job
	from customers as c join customer_types as ct on (c.customertype = ct.customertype);
	commit;
	
	insert into temp_customersdim_2
	select t1.customerid,t1.customername,t1.branchid,t1.customertype,t1.customertypedescription,t1.nationalid,t1.phonenumber,t1.job,CURRENT_DATE,NULL,true,
	lead(customerkey) over (partition by cd.customerid) as nextcustomerkey,
	lag(customerkey) over (partition by cd.customerid) as previouscustomerkey
	from temp_customersdim_1 as t1 
	left join customersdim cd on (t1.customerid = cd.customerid)
	where (cd.customerid is null) or (cd.customerid is not null and not (t1.job = cd.job) and cd.currentflag);
	commit;
	
	
	
	insert into temp_customersdim_final as tcdf
	select customerid,customername,branchid,customertype,customertypedescription,nationalid,phonenumber,job,jobstartdate,jobenddate,currentflag
	from temp_customersdim_2 as tcd2;
	commit;

	
	merge into customersdim as tcdf 
	using temp_customersdim_2 as tcd2
	on tcdf.customerid = tcd2.customerid
	when not matched then
		insert (customerid,customername,branchid,customertype,customertypedescription,nationalid,phonenumber,job,jobstartdate,jobenddate,currentflag)
		values (customerid,customername,branchid,customertype,customertypedescription,nationalid,phonenumber,job,jobstartdate,jobenddate,currentflag)
	when matched and tcd2.job <> tcdf.job THEN 
		update set currentflag = FALSE,jobenddate = CURRENT_DATE;
	commit;
					

end;
$$ language plpgsql;

call updateCustomerDimension();





	


INSERT INTO "public"."customers" ("customerid", "customername", "branchid", "customertype", "nationalid", "job", "phonenumber") VALUES (6, 'Kenny Lamar', 101, 2, 'F132412312', 'Singer', '555-4123');


INSERT INTO "public"."customers" ("customerid", "customername", "branchid", "customertype", "nationalid", "job", "phonenumber") VALUES (7, 'Will Smith', 105, 1, 'H123532312', 'Actor', '555-5234');
