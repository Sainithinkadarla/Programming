prompt ----------------------------------INTERNAL EXAM QUESTION----------------------------------------;
set serveroutput on

declare
    result number;
begin 
    select length(313)
      into result
      from dual;
    
    dbms_output.put_line('The nuber of digits are '||result);

end;
/

prompt ----------------------------------Palindrome----------------------------------------;

declare
  s varchar(20) := 'abccba';
  l varchar(20);
begin

  for i in reverse 1..length(s) loop
    l:=l||substr(s,i,1);
    end loop;

  if s=l then 
  dbms_output.put_line('palindrome');
else
  dbms_output.put_line('not palindrome');
end if;
end;
/

select * from emp e where sal>(select avg(sal) from emp a where a.deptno = e.deptno);

--accept r prompt 'sfsfsf';
select distinct sal, rank from (select sal , dense_rank() over (order by sal asc) as rank from emp);


create or replace procedure k(dept in integer)
is
begin
for i in (select * from emp join salgrade on sal between losal and hisal where deptno=dept) loop
dbms_output.put_line(i.empno||' '||i.ename||' '||i.grade);
end loop;
end;



--- sundays

create or replace procedure sun(k in pls_integer)
as
  i pls_integer;
  j pls_integer := 0;
  x date :='01-jan-'||k;
  y varchar2(10);
begin
  while y<>'SUNDAY' loop
    select to_char(x,'DAY') into y from dual;
    exit when y='SUNDAY';
    x:=x+1;
  end loop;
  while to_char(x,'YYYY') <> k+1 loop
    dbms_output.put_line(to_char(x,'DD-MON-YYYY'));
    x:=x+7;
    j:=j+1;
  end loop;
  dbms_output.put_line(j);
end;
/