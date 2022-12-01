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
	if(head)
		head=t;
	else
		tail->link=t;
	tail=t;
}

struct node *traverse()
{
	struct node *t;
	t=head;
	while(t)
	{
		printf("%d\t",t->data);
		t=t->link;
	}
}	

struct node *delete()
{
	struct node *t=tail;
	if (head)//terminates at head equals to NULL
	{
		
	}

}

struct node *insertbetween(int before, int after)
{

}
void main()
{
	/*struct node *n1=getnode(10);
	printf("data= %d    link=%p",n1->data, p);*/
	int i=0;
	insert();
	insert();
	insert();
	insert();
	
	
	traverse();
	printf("data= %d    link=%p",head->data, head);
	printf("data= %d    link=%p",tail->data, tail);
}
