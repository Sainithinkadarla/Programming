@emp.sql

drop emp_grade;
create table emp_grade as select * from emp e join salgrade s on sal between s.losal and s.hisal;

alter table emp add (grade int);
update emp set emp.grade = (select emp_grade.grade from emp_grade where emp.empno=emp_grade.empno) ;
drop table emp_grade;
desc emp;
select * from emp;


--select * from emp_grade;
