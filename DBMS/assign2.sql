---List of tables available ----
------EMP
------DEPT
------BONUS
------SALGRADE
------DUMMY


set wrap off;
set lines 50;
set linesize 150;

desc emp;
-- 1st question
select * from emp;
-- 2nd question
select distinct job from emp;
-- 3rd question
select * from emp where job='MANAGER';

--4th question

select * from emp where HIREDATE<'01-JAN-81';

alter table emp add (experience number);
update emp set experience=trunc((SYSDATE-HIREDATE)/365.25,1);
-- 5th question
select EMPNO,ENAME, job, HIREDATE, experience from emp;

-- 6th question
select EMPNO, ENAME,SAL,experience from emp where MGR='7639';

-- 7th question
select * from emp where COMM>SAL;

-- 8th question
alter table emp add (daily_sal number);
update emp set daily_sal=trunc((sal)/30);
select ename,experience,sal,daily_sal from emp where daily_sal>100;

-- 9th question
select * from emp where DEPTNO =10 or DEPTNO=20;

-- 10th question
select * from emp where MGR is not null;

-- 11th quesstion
select * from emp where job='CLERK' AND DEPTNO =20;

-- 12th question
select * from emp where ename='SMITH';

-- 13th question
select EMPNO, ENAME, DEPTNO from emp;


-- 14th question
select EMPNO, DEPTNO FROM EMP;

--15th question
select distinct DEPTNO from emp;

-- 16th question
select * from emp where (sal+(sal*(20/100)))>3000;

-- 17th question
select ename,sal, (sal+(sal*(15/100)))/80 as sal_in_dollars from emp;

-- 18th question
create table emp_and_job as select ename,job from emp;
select * from emp_and_job;
desc emp_and_job;

-- 19th question
select EMPNO, ename,sal from emp where job='MANAGER';

-- 20th question

select * from emp where (sal*12)>30000;
-- 21th question
select distinct EMPNO from emp;

-- 22nd question
select EMPNO, sal, comm from emp;


--23rd question 
select distinct DEPTNO from emp;

--24th question
select * from emp where ename='BLAKE';

--25th question
select * from emp where job='CLERK';   

--26th question
select ename from emp where HIREDATE='1-may-1981';

--27th question 
select * from emp where sal<3500;

--28th question 
select EMPNO, ename, sal from emp where HIREDATE<'1-apr-1981';

--29th question
select * from emp where experience>10;


drop table emp_and_job;