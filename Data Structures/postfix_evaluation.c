#include<stdio.h>
#include<stdlib.h>


int n=10, top=-1,a[10];

void push(int operand)
{
    if(top<n-1)
    {
        a[++top]=operand;
    }
}

int pop()
{
    return a[top--];
}

void main()
{
    char expression[20];
    int n1,n2,n3,num;
    printf("Enter the expression: ");
    scanf("%s",expression);
    int sp=0;
    
    while(expression[sp]!='\0')
    {
        if(expression[sp]=='0' || expression[sp]=='1' || expression[sp]=='2' || expression[sp]=='3' || expression[sp]=='4' || expression[sp]=='5' || expression[sp]=='6' || expression[sp]=='7' || expression[sp]=='8' || expression[sp]=='9')
        {
            push(((int)expression[sp])-48);
        }
        else
        {
            n1=pop();
            n2=pop();
            if(expression[sp]=='+')
            {
                n3=n2+n1;
                push(n3);
            }
            if(expression[sp]=='-')
            {
                n3=n2-n1;
                push(n3);
            }
            if(expression[sp]=='*')
            {
                n3=n2*n1;
                push(n3);
            }
            if(expression[sp]=='/')
            {
                n3=n2/n1;
                push(n3);
            }
            if(expression[sp]=='%')
            {
                n3=n2%n1;
                push(n3);
            }
        }
        sp++;
    }
    printf("\n%d\n",pop());
}