SELECT table_name, comments FROM user_tab_comments where table_name ='STUDENT';

SELECT comments FROM user_tab_comments where table_name='STUDENT';

SELECT owner FROM all_tab_comments where owner='SYS';



-- SELECT owner, table_name, comments FROM all_tab_comments ;


SELECT column_name, comments FROM user_col_comments where table_name='STUDENT';


SELECT owner, table_name, comments FROM all_col_comments where table_name='STUDENT';


SELECT
    TABLE_NAME,
    COLUMN_NAME,
    CONSTRAINT_NAME,
    POSITION
FROM
    USER_CONS_COLUMNS
WHERE
    TABLE_NAME = 'COMMITEMEM' AND
    COLUMN_NAME = 'BEGIN_DATE';


    SELECT
    TABLE_NAME,
    COLUMN_NAME,
    CONSTRAINT_NAME,
    POSITION
FROM
    USER_CONS_COLUMNS
WHERE
    TABLE_NAME = 'TEAMS';




SELECT *
FROM emp
WHERE CHAR_LENGTH(your_column) = 3






SELECT
    CONSTRAINT_NAME,
    CONSTRAINT_TYPE,
    TABLE_NAME,
    SEARCH_CONDITION
FROM
    USER_CONSTRAINTS
WHERE
    TABLE_NAME = 'TEAMS';




SELECT * FROM (SELECT * FROM your_table WHERE ROWNUM <= 5);


SELECT e.EMPNO, e.ENAME, e.experience, s.grade
FROM emp e
JOIN salgrade s ON e.sal BETWEEN s.losal AND s.hisal
WHERE s.grade = 3;



select emp.experience,emp.sal, salgrade.grade from emp JOIN SALGRADE on emp.sal BETWEEN SALGRADE.losal and salgrade.hisal where grade=3;




select emp.sal from emp JOIN SALGRADE on emp.sal BETWEEN SALGRADE.losal and salgrade.hisal where grade=3 and emp.experience=(select MAX(emp.experience) from emp);



--- 6th question

alter table emp add (grade int);
--update emp set grade = 
update emp set grade=(select grade from (select * from emp join salgrade on emp.sal between salgrade.losal and salgrade.hisal));
--update emp set sal=(select emp.sal from emp JOIN SALGRADE on emp.sal BETWEEN SALGRADE.losal and salgrade.hisal where grade=3) where emp.experience=(select MAX(emp.experience) from emp);

select * from emp;
---select sal, experience,ename from emp where experience= (select MAX(experience) from emp) and where job='CLERK';










select sal from (select * from emp join salgrade on sal between salgrade.losal and hisal where grade=3) where experience = (select max(experience) from (select * from emp join salgrade on sal between salgrade.losal and hisal where grade=3));



UPDATE EMP senior_clerk SET senior_clerk.SAL = (SELECT MAX(e.SAL) FROM EMP e JOIN SALGRADE s ON e.SAL BETWEEN s.LOSAL AND s.HISAL
    WHERE e.JOB = 'CLERK'
      AND e.HIREDATE = (
        SELECT MAX(HIREDATE)
        FROM EMP
        WHERE JOB = 'CLERK'
      )
)
WHERE senior_clerk.JOB = 'CLERK';




update emp set sal= (select max(sal) from emp where grade=3 ), experience = (select max(experience) from emp) where job= 'CLERK';




-- 6th question refernce

UPDATE tableDestination  
SET tableDestination.col = value  
WHERE EXISTS (  
SELECT col2.value  
FROM  tblSource  
WHERE tblSource.join_col = tblDestination. Join_col  
AND  tblSource.Constraint = value)  


You can also try this one -

UPDATE   
Table   
SET  
Table.column1 = othertable.column 1,  
Table.column2 = othertable.column 2  
FROM   
Table  
INNER JOIN  
Other_table  
ON  
Table.id = other_table.id  

--7th question reference with CASE statements
UPDATE Employee
SET Middle_Name 
= CASE Employee_ID
WHEN 7369 THEN 'A'
WHEN 7499 THEN 'B'
ELSE Middle_Name
END
WHERE Employee_ID IN(7369,7499);

-- bard for 7th question
UPDATE Employee
SET Middle_Name = CASE Employee_ID
WHEN 7369 THEN 'A'
WHEN 7499 THEN 'B'
ELSE Middle_Name
END,
Salary = CASE Employee_ID
WHEN 7369 THEN 3000
WHEN 7499 THEN 4000
ELSE Salary
END
WHERE Employee_ID IN(7369,7499);


--- 11th question rough work

select * from emp e join salgrade s on sal between s.losal and s.hisal where s.grade=2

update emp set grade= (select s.grade from emp e join salgrade s on sal between s.losal and s.hisal);

UPDATE target_table AS t SET t.target_column = s.source_column FROM source_table AS s WHERE t.condition_column = s.condition_column;

update emp e set e.grade = (select s.grade from (select s.grade from emp e join salgrade s on sal between s.losal and s.hisal)) where e.sal = ;






--- 19th question
select * from emp e join salgrade s on sal between s.losal and s.hisal where grade=2;
update emp set sal = sal +300 where EXISTS (select * from emp e join salgrade s on sal between s.losal and s.hisal where grade=2);




create table emp_grade as select * from emp e join salgrade s on sal between s.losal and s.hisal;



Write update statement to increment the Sal of grade 2 by 1.2%.



DELETE FROM EMP e1 WHERE EXISTS ( SELECT 1 FROM EMP e2 WHERE e1.EMPNO = e2.EMPNO AND e1.ENAME = e2.ENAME AND e1.ROWID > e2.ROWID);


select * from emp e1 where exists (SELECT 1 FROM EMP e2 WHERE e1.EMPNO = e2.EMPNO AND e1.ENAME = e2.ENAME AND e1.ROWID > e2.ROWID);