@emp.sql;
set wrap off;
set lines 50;
set linesize 150;

-- 1st question 
select * from emp where deptno= (select deptno from dept where dname = 'RESEARCH');

-- 2nd question
select * from emp where deptno in (select deptno from dept where loc in ('CHICAGO', 'NEW YORK'));

-- 3rd question
select dname from dept where deptno in (select distinct(deptno) from emp where job = 'ANALYST');

-- 4th question
select * from emp where mgr = (select empno from emp where ename= 'JONES');

-- 5th question
select * from emp where mgr = (select mgr from emp where ename='JONES');

-- 6th question
select * from emp where empno in (select mgr from emp where deptno in (select deptno from dept where dname in ('SALES', 'ACCOUNTING')));


-- 7th question
select * from emp where empno in (select mgr from emp group by mgr having count(*)>=2);

/*
select * from emp where deptno in (select deptno from dept group by deptno where dname in ('ACCOUNTING', 'RESEARCH')) AND empno in (select mgr from emp group by mgr having count(*)>=2); */

-- 8th question 
select * from emp where empno not in (select distinct(mgr) from emp where mgr is not null);

-- 9th question
select * from dept where deptno in (select deptno from emp group by deptno having count(*)>5);

-- 10th question
select dname from dept where deptno in (select deptno from emp group by job,deptno having count(*)>=3);

-- 11th question
select * from emp where empno in (select mgr from emp group by mgr having count(*)>=2) and deptno in (select deptno from dept where dname in ('RESEARCH','ACCOUNTING'));

-- 12th question
select * from emp where empno in (select mgr from emp group by mgr having count(*)>=1) and deptno in (select deptno from dept where dname in ('SALES', 'RESEARCH'));

-- 13th question 
select max(sal) from emp where sal<(select max(sal) from emp);

-- 14th question
select deptno, max(sal) from emp group by deptno ;

/*
--- test area

select * from dept e where exists (select 1 from emp m where e.deptno = m.deptno);

select 1 from emp where deptno =10;
*/