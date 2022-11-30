#include<stdio.h>
#include<stdlib.h>

struct node *getnode(int data); //create node
struct node *insert();//inserting node
struct node *traverse();

//creating structure
struct node
{
	int data;
	struct node *link;
};

struct node *p,*t,*head=NULL,*tail;

struct node *getnode(int data)//creating node
{
	struct node *p =(struct node *)malloc(sizeof(struct node));
	p->data=data;
	p->link=NULL;
	return p;
}

struct node *insert()
{
	int data;
	printf("Enter the data to insert: ");
	scanf("%d",&data);
	struct node *t=getnode(data);
	if(head==NULL)
		head=t;
	else
		tail->link=t;
	tail=t;
}

struct node *traverse()
{
	struct node *t;
	t=head;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t=t->link;
	}
}	

void main()
{
	/*struct node *n1=getnode(10);
	printf("data= %d    link=%p",n1->data, p);*/
	insert();
	insert();
	insert();
	traverse();
			
}
