conn system/ora1234;
alter session set "_oracle_script"= true;
drop user vedh;

@demotable.sql

alter session set "_oracle_script"= true;
create user vedh identified by vedh1234;

create or replace PUBLIC synonym stu for student;
create or replace synonym stu_priv for student;

grant connect, resource to vedh;
grant select on stu to vedh;
grant select on stu_priv to vedh;

conn vedh/vedh1234;
show user;

select * from stu;

prompt --------------- Accessing a private synonym ---------------;
select * from stu_priv;


conn system/ora1234;

drop PUBLIC synonym stu;
drop synonym stu_priv;





