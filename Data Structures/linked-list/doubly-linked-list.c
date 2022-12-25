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
    struct node *temp=previous;
    next=previous;
    previous=temp;
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

void search()
{
    int key,flag=0;
    t=head;
    printf("\nEnter the key to search in the linked list: ");
    scanf("%d",&key);
    while(t)
    {
        if(t->data==key)
            flag=1;
        t=t->next;
    }
    if(flag==1)
        printf("\n%d is found\n",key);
    else
        printf("\n%d is not found\n",key);
}

struct node *delete()
{
    t=head;
    if(head)
    {
        if(head->next)
        {
            head=head->next;
            printf("%d deleted\n",t->data);
            free(t);
        }
        else
        {
            printf("%d deleted\n",t->data);
            free(t);
            head=NULL;
            tail=NULL;
        }

    }
    else
    {
        printf("\nlinked list is empty");
    }
}

void insertatstart()
{
    int data;
    printf("\nEnter the data to insert: ");
    scanf("%d",&data);
    t=getnode(data);
    if(head)
    {
        head->previous=t;
        t->next=head;
    }
    head=t;
}

void deleteatend()
{
    if(head)
    {
        for(t=head; t->next!=tail; t=t->next)
        {}
            t->next=tail->next;
            printf("\n%d deleted\n",tail->data);
            free(tail);
            t=tail;
    }
    else
    {
        printf("\nlinked list is empty");
    }
}

void insertatrandom(int index)
{
	int data, counter;
	printf("\nEnter the data to insert: ");
	scanf("%d",&data);
    t=getnode(data);
    struct node *count=head;
	if(head)
	{
        for(counter=1; count; counter++)
        {
            if(counter==index-1)
            {
                t->next=count->next;
                t->next->previous=t;
                count->next=t;
                t->previous=count; 
            }
            count=count->next;
        }
	}
	else
	{
		head=t;
	}
}

void deleteatrandom(int index)
{
    int counter;
    struct node * count=head;
    if(head)
    {
        for(counter=1; count; counter++)
        {
            if(counter==index-1)
            {
                t=count->next;
                printf("\n%d deleted\n",t->data);
                count->next=t->next;
                t->next->previous=count;
                free(t);
            }
            count=count->next;
        }
    }
    else
    {
        printf("\nLinked list is empty");
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
    deleteatrandom(2);
    deleteatrandom(2);
    display();
}