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

begin 

dbms_output.put_line('dsfsadfdfasdfsad');

end;
/



prompt ----------------------------------INTERNAL EXAM QUESTION----------------------------------------;
set serveroutput on

declare
result number;
begin 
    select length(&number)
      into result
      from dual;
    
    dbms_output.put_line('The nuber of digits are '||result);

end;
/