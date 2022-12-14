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
	printf("hi");		
    }
}
struct node *display()
{
	t=head;
	do
	{
		printf("%d\t",t->data);		
		t=t->link;
	}while(t!=head);


}

void main()
{
	insert();
	insert();
	insert();
	insert();
	display();
}
