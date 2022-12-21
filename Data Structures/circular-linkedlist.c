#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *link;
}*head=NULL, *tail=NULL, *t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->link=NULL;
    return t;
}

struct node *insert()//at end
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
 	tail->link=head;   
}

struct node *delete()//at first
{
    t=head;
    if(head)
    {
        head=head->link;
        if (head->link==head)
        {
            printf("\n%d deleted",t->data);
            head=NULL;
            tail=NULL;
            free(t);
        }
        else
        {
            printf("\n%d deleted",t->data);
            free(t);
            tail->link=head;
        }
    }
    else
    {
        printf("\nlinked list is empty");
    }
}

struct node *display()
{
	t=head;
    if(head)
    {
	    
        while(t->link!=head)
        {
            printf("\t%d\t",t->data);		
            t=t->link;
        }
        printf("\t%d\t",t->data);
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
    printf("\nEnter the data to search in linked list: ");
    scanf("%d",&key);
    while(t->link!=head)
    {
        if(t->data==key)
            flag=1;	
        t=t->link;
    }
    if(t->data==key)
        flag=1;
    if(flag==1)
        printf("\n%d is found",key);
    else
        printf("\n%d is not found",key);
}

void deleteend()
{
    t=head;
    if(head)
    {
        while(t->link!=tail)
        {
            t=t->link;
        }
        printf("\n%d deleted",t->data);
        t->link=head;
        free(tail);
        tail=t;
    }
    else
    {
        printf("\nlist is empty");
    }
}

void insertfromstart()
{
    int data;
    printf("\nEnter the data to insert: ");
    scanf("%d",&data);
    t=getnode(data);
    if(head)
    {
        t->link=head;
    }
    head=t;
    tail->link=head;
}

void main()
{
	int i;
    for (i=0; i<4;i++)
    insert();
    display();
    search();
}