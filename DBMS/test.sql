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
