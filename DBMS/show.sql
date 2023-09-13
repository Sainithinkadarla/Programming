
-- default constraint
create table test(id number, city varchar(20) default 'Hyderabad');

insert into test values(1, 'pune');
insert into test(id) values(2);

select * from test;

-- read-only tables

alter table test read only;
prompt ------After table changed to read only-------;
insert into test values(1, 'pune');

alter table test read write ;
prompt ------After table changed to read write-------;

insert into test(id) values(2);

-- GTT with ON COMMIT andd ON ROLLBACK
-- default is on commit delete rows is set

-- ON COMMIT
create GLOBAL TEMPORARY TABLE test1 (id number, name varchar(10));

insert into test1 values(11,'alan');
insert into test1 values(12,'jeffos');

select * from test1;

create GLOBAL TEMPORARY TABLE test2 (id number, name varchar(10)) on commit PRESERVE ROWS;

insert into test2 values(11,'alan');
insert into test2 values(12,'jeffos');

select * from test2;

create GLOBAL TEMPORARY TABLE test3 (id number, name varchar(10)) on commit DELETE ROWS;

insert into test3 values(11,'alan');
insert into test3 values(12,'jeffos');

select * from test3;

commit;

select * from test3;

-- ON ROLLBACK
create GLOBAL TEMPORARY TABLE temp1 (id number, name varchar(20)) on rollback PRESERVE ROWS;

insert into temp1 values (11, 'mark');
select * from temp1;
rollback;
insert into temp1 values (12, 'stephen');

select * from temp1;

create GLOBAL TEMPORARY TABLE temp2 (id number, name varchar(20)) ON COMMIT PRESERVE ROWS ON ROLLBACK DELETE ROWS;

insert into temp1 values (11, 'Grant');
select * from temp1;
rollback;
insert into temp1 values (12, 'aris');

select * from temp1;

-- undefine command

define jerry = 'Jerry variable';

prompt This is a variable created with define statement : &jerry;
prompt  -------------------------------------;
undefine jerry;
define jerry;
prompt  -------------------------------------;

-- foreign key on delete set null and cascade

create table student(id number, name varchar(20), schl_id number);

insert into student values(1, 'Sai', 101);
insert into student values(2, 'Nithin', 101);
insert into student values(3, 'Nikhil', 102);
insert into student values(4, 'Chinnu', 103);
insert into student values(5, 'Harsha', 103);
insert into student values(6, 'Siri', 101);
insert into student values(7, 'CHandana', 102);


select * from student;


create table school (schl_id number, schl_name varchar(30), constraint schl_pk primary key(schl_id));

insert into school values (101,'Shine');
insert into school values (102,'Cambridge');
insert into school values (103,'geetha');

select * from school;

alter table student add constraint student_fk foreign key(schl_id) references school(schl_id) on delete set null;

delete from school where schl_name='geetha';

select * from school;
select * from student;

drop table student;
drop table school;
drop table temp1;
drop table temp2;
drop table test1;
drop table test2;
drop table test3;
drop table test;