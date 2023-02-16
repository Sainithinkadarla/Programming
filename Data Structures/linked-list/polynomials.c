#include<stdio.h>
#include<stdlib.h>

char seperated[10][10];
char expression[]="4x^3+3x^2";
int term_index=0;


struct term
{
    int coef;
    int pow;
    struct term *link;
}*head=NULL, *tail=NULL, *t;


struct term *getnode(int coef, int pow)
{
    t=(struct term *)malloc(sizeof(struct term));
    t->coef=coef;
    t->pow=pow;
    t->link=NULL;
    return t;
}

void insert_to_nodes(int coefficient, int power)
{
    t=getnode(coefficient,power);
    if(head)
    {
        tail->link=t;
    }
    else
    {
        head=t;
    }
    tail=t;
}



void seperation(char exp[])
{   
    int start=0, end=0;
    for(int i=0;exp[i]!='\0';i++)
    {
        if(exp[i+1]=='+' || exp[i+1]=='\0')
        {
            end=i;
            int expression_index=0;
            for(int j=start; j<=end; j++,expression_index++)
            {
                seperated[term_index][expression_index]=exp[j];
            }
            term_index+=1;
            start=end+2;
        }
    }
}

void linked()
{
    for(int i=0; i<term_index; i++)
    {
        for(int j=0;seperated[i][j]!='\0';j++)
        {
            if()
            {
                
            }
        }
    }
}

void main()
{
  seperation(expression);
  linked();
}