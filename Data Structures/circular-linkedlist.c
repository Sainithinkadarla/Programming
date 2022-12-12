#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct nod *link;
}*head=NULL, *tail=NULL, *t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->link=NULL;
    return t;
}

struct node *insert()
{
    int data;
    printf("\nEnter the data to insert: ");
    scanf("%d",&data);
    t=getnode(data);
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

struct node *delete()
{
    t=head;
    if(head)
    {

    }
}