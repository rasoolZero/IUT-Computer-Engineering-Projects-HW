CREATE TABLE BankPaymentFactDaily (
  loanid INT NOT NULL,
  paymentdate date NOT NULL,
  totalamount decimal(18,2),
  minimumamount decimal(18,2),
  maximumamount decimal(18,2)
)
PARTITION BY RANGE (
  paymentdate
);

CREATE TABLE p1 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-20') TO ('2024-05-21');

CREATE TABLE p2 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-21') TO ('2024-05-22');

CREATE TABLE p3 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-22') TO ('2024-05-23');

CREATE TABLE p4 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-23') TO ('2024-05-24');

CREATE TABLE p5 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-24') TO ('2024-05-25');

CREATE TABLE p6 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-25') TO ('2024-05-26');

CREATE TABLE p7 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-26') TO ('2024-05-27');

CREATE TABLE p8 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-27') TO ('2024-05-28');

CREATE TABLE p9 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-28') TO ('2024-05-29');

CREATE TABLE p10 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-29') TO ('2024-05-30');

CREATE TABLE p11 PARTITION OF BankPaymentFactDaily FOR VALUES FROM ('2024-05-30') TO ('2024-05-31');



SELECT
  relname AS bankpaymentfactdaily,
  pg_size_pretty(pg_total_relation_size(relid)) AS total,
  pg_size_pretty(pg_relation_size(relid)) AS internal,
  pg_size_pretty(pg_table_size(relid) - pg_relation_size(relid)) AS external,
  pg_size_pretty(pg_indexes_size(relid)) AS indexes
	
FROM pg_catalog.pg_statio_user_tables 
ORDER BY relid DESC;







