@emp.sql;
set wrap off;
set lines 50;
set linesize 150;

-- 1st question
select * from emp e join dept d on e.deptno=d.deptno where d.dname in ('ACCOUNTING','RESEARCH');

-- 2nd question
alter table emp add (experience number);
update emp set experience=trunc((SYSDATE-HIREDATE)/365.25,1);
update emp set comm = NULL where comm=0;

select e.empno, e.ename, e.sal, d.dname from emp e join dept d on e.deptno=d.deptno where job in ('MANAGER', 'ANALYST') and d.loc in ('NEW YORK','DALLAS') and e.experience > 7 and e.comm is null;

-- 3rd question
alter table emp add (ann_sal number);
update emp set ann_sal=(sal*12);

SELECT e.empno, e.ename, e.sal, d.deptno, d.dname, d.loc, e.job from emp e join dept d on e.deptno=d.deptno where d.loc='CHICAGO' or e.job='ACCOUNTING' and ann_sal>28000 and sal not in (3000,2800) and job!='MANAGER' and substr(e.empno,3,1) in ('7','8') order by e.deptno asc, e.job desc;

-- 4th question
create table emp_grade as select * from emp e join salgrade s on sal between s.losal and s.hisal;

alter table emp add (grade int);
update emp set emp.grade = (select emp_grade.grade from emp_grade where emp.empno=emp_grade.empno) ;

drop table emp_grade;


SELECT * from emp ORDER BY grade ASC;

-- 5th question
SELECT empno, ename, sal, salgrade.grade FROM emp JOIN salgrade ON emp.sal BETWEEN salgrade.losal AND salgrade.hisal ORDER BY salgrade.grade ASC;

-- 6th question
SELECT * from emp e  join salgrade s on e.sal between s.losal and s.hisal where e.grade in (2,3);

-- 7th question 
SELECT * from emp e join salgrade s on e.sal BETWEEN s.losal and s.hisal where e.grade in (4,5) and job in ('ANALYST', 'MANAGER');

-- 8th question
SELECT e.empno, e.sal, d.dname, e.grade, e.experience, e.ann_sal from emp e join dept d on e.deptno=d.deptno where e.deptno in (10,20);

-- 9th question
SELECT * from dept left join emp on emp.deptno = dept.deptno;

-- 10th question
SELECT * from emp e join emp m on e.mgr=m.empno where e.experience > m.experience;

-- 11th question
SELECT * from emp e join emp em on e.job=em.job where e.deptno = 20 and em.deptno=10;


-- 12th question
SELECT e.ename, e.sal FROM emp e JOIN emp f ON e.sal = f.sal WHERE f.ename IN ('FORD', 'SMITH') ORDER BY e.sal DESC;

-- 13th question 
select e.ename, e.job, e.sal from emp e left join emp m on e.job=m.job and m.ename='MILLER' where m.ename is not null or e.sal > (select sal from emp where ename='ALLEN');
select e.ename, e.job, e.sal from emp e left join emp m on e.job=m.job and m.ename='MILLER' where m.ename is not null or e.sal > (select sal from emp where ename='ALLEN');

-- 14th question
select e.ename, d.dname, d.loc from emp e natural join dept d where d.loc in ('CHICAGO','BOSTON') and experience>(select experience from emp where ename='BLAKE');

-- 15th question
select ename from emp e natural join dept d where e.grade in (3,4) and d.dname in ('ACCOUNTING','RESEARCH') and e.sal > (select sal from emp where ename='ALLEN') and experience > (select sal from emp where ename='SMITH') order by experience ASC ;

-- 16th question
select es.ename, es.job from emp es join emp ea on es.job=ea.job where ea.ename in ('ALLEN','SMITH');

-- 17th question

select * from emp e join salgrade s on sal between s.losal and s.hisal natural join dept d where d.loc='CHICAGO';

-- 18th question
select e.ename, d.loc from emp e natural join dept d;

-- 19th question
select e.ename, d.dname from emp e natural join dept d where d.dname != 'SALES';

-- 20th question
select * from emp e natural join dept d where d.loc = 'CHICAGO' and sal between 2000 and 5000;

-- 21th question
select ee.empno, ee.ename, ee.sal from emp ee join emp em on ee.mgr=em.empno where ee.sal>em.sal;

-- 22nd question
select e.ename, e.grade, e.deptno, s.grade, e.HIREDATE from emp e join salgrade s on e.sal between s.losal and s.hisal where e.deptno in (10,30) and s.grade !=4 and e.HIREDATE='31-DEC-1982';  

-- 23rd question
select e.ename, e.job, d.dname, d.loc from emp e natural join dept d where job='MANAGER';

-- 24th question
select empno,ename, mgr  from emp where mgr=(select empno from emp where ename='JONES') or empno=(select mgr from emp where ename='JONES');

-- 25th question
select ename, sal from emp where ename='FORD' and sal = (select hisal from salgrade where grade = (select s.grade from emp e join salgrade s on e.sal between s.losal and s.hisal where e.ename='FORD')); 

-- 26th question
select e.ename, e.job, d.dname, e.mgr, e.sal, s.grade from emp e natural join dept d join salgrade s on e.sal between s.losal and s.hisal order by deptno, grade;

-- 27th question
select ename, job, mgr from emp where mgr is null;

-- 28th question
with emp_netpay (empno, ename, sal, comm, netpay) as (select empno, ename, sal, comm, sal+comm as netpay from emp),
with greater_than_net (select distinct e.empno, e.ename, e.sal, e.comm,  n.ename, n.netpay from emp e join emp_netpay n on e.sal<=n.netpay)

select distinct empno from greater_than_net;


with emp_netpay (empno, ename, sal, comm, netpay) as (select empno, ename, sal, comm, sal+comm as netpay from emp)
select distinct e.empno, e.ename, e.sal, e.comm,  n.ename, n.netpay from emp e join emp_netpay n on e.sal<=n.netpay;


-- 29th question
with emp_mgr as (select e.ename, e.sal, e.mgr from emp e join emp m on e.mgr=m.empno)
select * from emp_mgr where ; 

select e.empno, e.ename, e.sal, e.mgr from emp e join emp m on e.mgr=m.empno where e.sal<m.sal and e.sal > (select sal from emp));
/*
 
select * from emp_netpay;
select * from emp e join emp_netpay n on e.empno=n.empno where e.sal<=n.netpay;



select ee.empno, ee.ename, ee.sal from emp ee join emp em on ee.sal>em.sal;
--select * from emp e join emp m on e.job=m.job and m.ename='MILLER' where m.ename is not null or e.sal > (select sal from emp where ename='ALLEN') select job from emp where ename in ('ALLEN','SMITH');@emp.sql;;


WITH emp_mgr_sal AS (
  SELECT e.empno, e.ename, e.sal, e.comm, m.sal AS mgr_sal
  FROM emp e
  JOIN emp m ON e.mgr = m.empno
),
emp_higher_mgr_sal AS (
  SELECT e.empno, e.ename, e.sal, e.comm, e.mgr_sal, MAX(mgr_sal) higher_mgr_sal
  FROM emp_mgr_sal e
  JOIN emp m ON e.mgr = m.empno
  GROUP BY e.empno, e.ename, e.sal, e.comm, e.mgr_sal
)
SELECT *
FROM emp_higher_mgr_sal AS e
WHERE e.sal < e.mgr_sal AND e.sal > e.higher_mgr_sal;


*/