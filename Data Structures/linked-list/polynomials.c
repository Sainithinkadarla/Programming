#include<stdio.h>
#include<stdlib.h>

char expression[]="4x^3";

struct term
{
    int num;
    int coef;
    int pow;
    struct term *link;
}*head, *tail, *t;


struct term *getnode(int num, int coef, int pow)
{
    t=(struct term *)malloc(sizeof(struct term));
    t->num=num;
    t->coef=coef;
    t->pow=pow;
    t->link=NULL;
    return t;
}

void insert_to_nodes()
{
    int num=0, coef=0, pow=0;
    for(int i=0; expression[i]; i++)
    {
        
        printf("\n%c",expression[i]);
    }
}

void justforunderstanding()
{
    int data=0, pow=0;
    t=getnode(data,pow ,0);
    printf("%d %d %d %p",t->num, t->coef, t->pow, t->link);
}

void evaluate()
{
    printf("\nI am nothing\n");
}

void main()
{
    
    insert_to_nodes();
    evaluate();
    insert_to_nodes();
    justforunderstanding();
}
