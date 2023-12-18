prompt ----------------------------------INTERNAL EXAM QUESTION----------------------------------------;
set serveroutput on

declare
    result number;
begin 
    select length(23423)
      into result
      from dual;
    
    dbms_output.put_line('The nuber of digits are '||result);

end;
/