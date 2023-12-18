prompt ---------------------------------------START OF EXECUTION-----------------------------------;
prompt -----------------------------------Basic Text Printing---------------------------------------;
set serveroutput on

declare

begin 

    dbms_output.put_line('dsfsadfdfasdfsad');

end;
/

prompt ------------------------------------variables--------------------------------------;

set serveroutput on

declare
    empname varchar(20);
    sal number :=500;
    tr constant number := 3453;
begin 

    dbms_output.put_line('dsfsadfdfasdfsad ' ||sal || ' ' || tr);

end;
/

prompt ----------------------------------Contrl Structures----------------------------------------;
set serveroutput on

declare
    score number:= 80;
begin 
    if score >=90 then
        dbms_output.put_line('Good');
    elsif score >= 70 then 
        dbms_output.put_line('Better');
    else 
        dbms_output.put_line('Improve yourself');
    end if;

end;
/



prompt -----------------------------------Cursors---------------------------------------;
prompt -----------------------------------Two types of cursors are there ---------------------------------------;

prompt -----------------------------------Implicit cursor---------------------------------------;


set serveroutput on

declare
    empname varchar(20);
begin 
    select ename
    into empname
    from emp
    where empno=7369;
    dbms_output.put_line('employee is '||empname);

end;
/

prompt -----------------------------------Explicit cursor---------------------------------------;


set serveroutput on

declare

    cursor ecursor is select ename from emp where deptno = 10;
    empname varchar(20);

begin 

    open ecursor;
    fetch ecursor into empname;
    close ecursor;

    dbms_output.put_line(empname);

end;
/


prompt -----------------------------------Exception handling---------------------------------------;
set serveroutput on

declare
    salary number;
begin 
    select sal into
      salary
      from emp
     where empno = 7369;

exception
  when no_data_found then
    dbms_output.put_line('Employee  not found');
  when others then   
    dbms_output.put_line('Some other error occurred please try again');

end;
/

prompt -----------------------------------Procedure---------------------------------------;
set serveroutput on

create or replace procedure display_proced (empid in number) as 
    empname varchar(20);

begin 
    select ename
      into empname
      from emp 
     where empno=empid;
    dbms_output.put_line('employee is '|| empname);

end;
/

declare 
begin
    display_proced(7369);
end;
/

prompt -----------------------------------Functions---------------------------------------;
set serveroutput on

create or replace function display_func (empid in number) return varchar as 
    empname varchar(20);

begin 
    select ename
      into empname
      from emp 
     where empno=empid;
     return empname;

end;
/

declare 
    result varchar(20);
begin
    result:=display_func(7369);
    dbms_output.put_line('result is '||result);
end;
/

