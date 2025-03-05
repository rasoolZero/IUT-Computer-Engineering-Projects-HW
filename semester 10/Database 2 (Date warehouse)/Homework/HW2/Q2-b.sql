
create or replace procedure updateLoansDimension() as $$
BEGIN
		if  (((select count(*) from loansdim) = 0) and (not (select count(*) from temp_loansdim_final) = 0)) then
			raise EXCEPTION 'danger of deleting loans dimension data, aborting procedure';
		end if;
			
	
	
	truncate temp_loansdim;
	truncate temp_loansdim_final;
	commit;
	
	
	insert into temp_loansdim 
	select ld.loanid,ld.loansubtype,ld.loansubtypedescription,ld.loantype,ld.loantypedescription,ld.branchid,ld.currencycode,ld.currencydescription,ld.approvaldate,ld.amount,ld.duration,ld.status
	from loansdim as ld;
	commit;

	

	insert into temp_loansdim_final
	select l.loanid,lt.loansubtype,lt.loansubtypedescription,lt.loantype,lt.loantypedescription,l.branchid,c.currencycode,c.currencydescription,l.approvaldate,l.amount,l.duration,l.status
	from
	loans as l join loan_types as lt on (l.loansubtype = lt.loansubtype)
	join currency as c on (l.currencycode = c.currencycode)
	left join temp_loansdim as tld on (l.loanid = tld.loanid)
	where tld.loanid is null or tld.amount <> l.amount;
	commit;
	
	insert into temp_loansdim_final
	select tld.loanid,tld.loansubtype,tld.loansubtypedescription,tld.loantype,tld.loantypedescription,tld.branchid,tld.currencycode,tld.currencydescription,tld.approvaldate,tld.amount,tld.duration,tld.status
	from
	loans as l join loan_types as lt on (l.loansubtype = lt.loansubtype)
	join currency as c on (l.currencycode = c.currencycode)
	left join temp_loansdim as tld on (l.loanid = tld.loanid)
	where tld.loanid is not null and tld.amount = l.amount;
	commit;
	
	
	
	truncate loansdim;
	commit;
	insert into loansdim 
	select tld.loanid,tld.loansubtype,tld.loansubtypedescription,tld.loantype,tld.loantypedescription,tld.branchid,tld.currencycode,tld.currencydescription,tld.approvaldate,tld.amount,tld.duration,tld.status
	from temp_loansdim_final as tld;
	commit;

	
end;
$$ language plpgsql;

call updateLoansDimension();

