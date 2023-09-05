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

alter table emp add (ann_sal number);
update emp set ann_sal=(sal*12);

select * from emp where ann_sal>30000;

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

-- 30th question
select * from emp where job='MANAGER';

-- 31st question
select * from emp where job='CLERK' and experience>8;

-- 32nd question
select EMPNO, ename, sal, job from emp where ann_sal<34000 and comm<sal and job='SALESMAN' and DEPTNO=20;

--33rd question
select * from emp where job='SALESMAN' and comm is not null and comm>0;

-- 34th question
select * from emp where job='SALESMAN' and DEPTNO=30 and comm>sal;

-- 35th question
with rec(n) as(select 100 as n from dual union all select n+1 from rec where n<999) select n from rec;

--36th question
select * from emp fetch first 5 rows only;

--37th question
select EMPNO, ename, job,sal from emp;

--38th question
select distinct DEPTNO from emp;

--39th question
select distinct job, DEPTNO from emp;

--40th question
select * from emp where ename='MILLER';

--41st question
select * from DEPT where DEPTNO=10;

--42nd question
select * from emp where job ='SALESMAN';

--43rd question
select * from emp where HIREDATE<'1-JAN-1984';

--44th question
select * from emp where sal>2500;

--45th question
select * from emp where HIREDATE>='1-APR-1982';

--46th question
select EMPNO, ename, sal, daily_sal from emp;

--47th question
select EMPNO,ENAME,sal, experience from emp where job='ANALYST';

--48th question
select * from emp where experience>6.5;

--49th question
select * from emp where HIREDATE>'1-jun-1981';

--50th question
select * from emp where DEPTNO=10 and job='CLERK';

--51st question 
select * from emp where HIREDATE<'1-JAN-1985' and sal>3000;

---52nd question
SELECT emp.EMPNO, emp.ENAME, emp.experience, salgrade.grade FROM emp
JOIN salgrade ON emp.sal BETWEEN salgrade.losal AND salgrade.hisal
WHERE salgrade.grade = 3;


-----------------------------------------------UPDATE COMMAND------------------------------

-- 1st question
update emp set DEPTNO = 30 where ename='BLAKE';
select * from emp where ename='BLAKE';

---2nd question
update emp set DEPTNO =20 where DEPTNO=10;
select DEPTNO from emp;

--3rd question
update DEPT set LOC='DALLAS' where LOC='CHICAGO';
select LOC from DEPT;

--4th question 
update emp set sal=(select salgrade.hisal from salgrade where salgrade.grade =2), DEPTNO = (select DEPTNO from emp where ENAME='BLAKE'), MGR= (select EMPNO from emp where ENAME='BLAKE') WHERE ename='ALLEN';

select ename,sal, DEPTNO, MGR from emp where ename='ALLEN';

--5th question
select * from emp;
update emp set sal=(sal+(sal*(2/100))), comm = (comm+250), mgr=(select EMPNO from emp where ename='JONES') where job='SALESMAN';
select * from emp;

drop table emp_and_job;

