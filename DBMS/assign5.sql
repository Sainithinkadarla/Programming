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

--select * from emp e join emp m on e.job=m.job and m.ename='MILLER' where m.ename is not null or e.sal > (select sal from emp where ename='ALLEN');