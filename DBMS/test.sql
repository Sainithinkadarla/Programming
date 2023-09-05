SELECT table_name, comments FROM user_tab_comments where table_name ='STUDENT';

SELECT comments FROM user_tab_comments where table_name='STUDENT';

SELECT owner FROM all_tab_comments where owner='SYS';



-- SELECT owner, table_name, comments FROM all_tab_comments ;


SELECT column_name, comments FROM user_col_comments where table_name='STUDENT';


SELECT owner, table_name, comments FROM all_col_comments where table_name='STUDENT';
