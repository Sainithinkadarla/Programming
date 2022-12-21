#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *previous;
    int data;
    struct node *next;
}*t,*head=NULL,*tail=NULL;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->previous=NULL;
    t->next=NULL;
    return t;
}

void insert()//from end
{
    int data;
    printf("\nEnter the data to insert: ");
    scanf("%d",&data);
    t=getnode(data);
    if(head)
    {
        tail->next=t;
        t->previous=tail;
        
    }
    else
    {
        head=t;
    }
    tail=t;
    tail->next=head;
    head->previous=tail;
}

void display()
{
    if(head)
    {
        for( t=head; t->next!=head; t=t->next)
        {
            printf("%d\t",t->data);
        }
        printf("%d",t->data);
    }
    else
    {
        printf("\nlinked list is empty");
    }
}

void delete()//from head
{
    if(head)
    {
        t=head;
        head=head->next;
        if(head->next!=head)
        {
            printf("\n%d deleted",t->data);
            free(t);
            tail->next=head;
            head->previous=tail;
        }
        else
        {
            printf("\n%d deleted",t->data);
            head=NULL;
            tail=NULL;
            free(t);
        }
    }
    else
    {
        printf("\nlinked list is empty");
    }
}

void search()
{
    int key,flag=0;
    t=head;
    printf("\nEnter the key to search in linked list: ");
    scanf("%d",&key);
    if(head)
    {
        for( t=head; t->next!=head; t=t->next)
        {
            if(t->data==key)
                flag=1;
        }
        if(t->data == key)
            flag=1;
    }
    if(flag==1)
        printf("\n%d is found\n",key);
    else
        printf("\n%d is not found\n",key);
}

void main()
{
    int i;
    for(i=0; i<4; i++)
        insert();
    display();
    search();

}