use AdventureWorks2012;

create user myuser for login [ECE-DBLAB10\ECE-DBLab10];

create role Role2;

alter role Role2 add member myuser;

alter role db_securityadmin add member myuser;

grant select to Role2;

