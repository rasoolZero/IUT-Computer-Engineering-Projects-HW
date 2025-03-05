--create login loginCode
--with password='1'

--grant create any database
--to loginCode

--alter server role dbcreator
--add member loginCode

--deny create any database
--to loginCode

--revoke create any database
--to loginCode

--create server role role1
--grant create any database
--to role1

--alter server role dbcreator
--drop member loginCode

--alter server role role1
--add member loginCode