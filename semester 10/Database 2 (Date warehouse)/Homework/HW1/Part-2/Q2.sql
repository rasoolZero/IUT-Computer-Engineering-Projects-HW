CREATE OR REPLACE PROCEDURE save_duplicates_temp()
LANGUAGE SQL
AS $$
	
	with duplicated as (
		select concat(t1.voucherid,'|', t2.voucherid) as voucherid,t1.trndate, t1.trntime,t1.amount,t1.sourcedep,t1.desdep
		from trn_src_des as t1 join trn_src_des as t2
		on (
			t1.voucherid < t2.voucherid
			and t1.trndate = t2.trndate
			and t1.trntime = t2.trntime
			and t1.amount = t2.amount
			and t1.sourcedep = t2.sourcedep
			and t1.desdep = t2.desdep
		)
		order by t1.voucherid, t2.voucherid)
	
	INSERT INTO trn_src_des_temp SELECT * FROM duplicated;
$$;


CREATE OR REPLACE PROCEDURE remove_duplilcates_main()
LANGUAGE SQL
AS $$
	WITH ids_to_remove as (
		SELECT SPLIT_PART(trn.voucherid,'|',1) FROM trn_src_des_temp as trn
		UNION
		SELECT SPLIT_PART(trn.voucherid,'|',2) FROM trn_src_des_temp as trn
	)
	
	DELETE from trn_src_des as trn
	WHERE trn.voucherid in (select * from ids_to_remove);
$$;


CREATE OR REPLACE PROCEDURE insert_duplcates_into_main()
LANGUAGE SQL
as $$
	INSERT INTO trn_src_des select * from trn_src_des_temp;
$$;

create or replace PROCEDURE clean_temp()
LANGUAGE SQL
as $$
	delete from trn_src_des_temp;
$$;


CREATE or replace PROCEDURE question2()
LANGUAGE SQL
as $$
	CALL save_duplicates_temp();
	CALL remove_duplilcates_main();
	CALL insert_duplcates_into_main();
	CALL clean_temp();
$$

CALL question2();