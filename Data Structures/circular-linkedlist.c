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
 	tail->link=head;   
}

struct node *delete()
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
	    do
        {
            printf("%d\t",t->data);		
            t=t->link;
        }while(t!=head);
    }
    else
    {
        printf("\nlinked list is empty");
    }

}

void main()
{
	int i;
    for (i=0; i<4;i++)
    insert();
    display();
    for (i=0; i<=4;i++)
    delete();
	display();
}