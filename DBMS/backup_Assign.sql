
--52th question
SELECT emp.EMPNO, emp.ENAME, emp.experience, salgrade.grade FROM emp
JOIN salgrade ON emp.sal BETWEEN salgrade.losal AND salgrade.hisal
WHERE salgrade.grade = 3;


--- update


---4th question
update emp set sal=(select salgrade.hisal from salgrade where grade =2), DEPTNO = (select DEPTNO from emp where ENAME='BLAKE'), MGR= (select EMPNO from emp where ENAME='BLAKE') WHERE ename='ALLEN';


--6th question
update emp set sal = (select sal from (select * from emp join salgrade on sal between salgrade.losal and hisal where grade=3) where experience = (select max(experience) from (select * from emp join salgrade on sal between salgrade.losal and hisal where grade=3))) where job ='CLERK' and experience = (select max(experience) from emp);



 select * from emp;
update emp set DEPTNO = case DEPTNO 
when 10 then 20
when 20 then 30
when 30 then 40
when 40 then 10
END, sal= case when comm is null then (sal*1.1) 
else sal
end;
select * from emp;


12, 20


. Update the sal of Allen with the highest Sal of any Clerk belongs to grade 2 or 3 working at Chicago or Dallas and king as manager.
for the mer


Transfer thc emps to analyst Dept and give the Sal of smith plus 500 to those belongs
to grade 3 working at New York or Dallas with an exp>7y name should not be
4 chars,