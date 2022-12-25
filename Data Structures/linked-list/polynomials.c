#include<stdio.h>
#include<stdio.h>


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
    t->lin=NULL;
}
