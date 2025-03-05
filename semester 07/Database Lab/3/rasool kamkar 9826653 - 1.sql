create login mylogin
with password='1234';

create server role Role1;

grant create any database to Role1;
grant alter any database to Role1;
grant view any database to Role1;
grant connect any database to Role1;

alter server role Role1
add member mylogin;
