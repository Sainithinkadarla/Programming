#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *previous;
    struct node *next;
} *t, *head=NULL, *tail=NULL;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->previous=NULL;
    t->next=NULL;
    return t;
}

struct node *swap(struct node *previous, struct node *next)
{
    t=previous;
    next=previous;
    previous=t;
}

struct node *insert()
{
    int data;
    printf("\nEnter data to insert: ");
    scanf("%d",&data);
    t=getnode(data);
    if(head)
    {
        tail->next=t;
        t->previous=tail;
        tail=t;
    }
    else
    {
        head=t;
    }
    tail=t;
}

struct node *display()
{
    t=head;
    if(head)
    {
        while(t)
        {
            printf("%d\t",t->data);
            t=t->next;
        }
    }
    else
    printf("\nlinked list is empty");
}

struct node *delete()
{
    t=head;
    if(head)
    {
        if(head)
        {
            head=head->next;
            printf("%d deleted\n",t->data);
            free(t);
        }
        else
        {
            printf("\nlinked list is empty");
        }
    }
}

void main()
{
    int i;
    for (i=0;i<4;i++)
    {
        insert();
    }
    display();
    for (i=0;i<=4;i++)
    {
        delete();
    }
    display();
}