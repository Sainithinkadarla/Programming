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
struct node *insertbetween(int index)
{
	int counter=1;//counter

	int data;//data to insert
	printf("Enter the data to insert: ");
	scanf("%d",&data);//reading data
	struct node *t=getnode(data);//new node which is going to be inserted
	
	struct node *c=head;//counting node

	while(c!=NULL)
	{
		c=c->link;
		
		if(counter==index-1)
		{
			printf("data=%d    counter=%d",c->data, counter);																	//TESTING
			t->link=c->link;
			c->link=t;
		}
		counter+=1;
	}
	printf("No. of nodes = %d",counter);
}
struct node *insertathead()
{
	int data;
	printf("Enter the data to insert: ");
	scanf("%d",&data);
	struct node *t=getnode(data);
	t->link=head;
	head=t;
}

struct node *traverse()
{
	struct node *t;
	t=head;
	int c=1;																		//TESTING
	while(t!=NULL)
	{
		printf("\n%d ",c);
		printf("%d\t",t->data);
		t=t->link;
		c+=1;
	}
}	

struct node *delete()
{
	struct node *t=head;
	if (head)//terminates at head equals to NULL
	{
		if(head->link)
		{
			head=head->link;
			printf("\n%d deleted",t->data);
			free(t);
		}
		else
		{
			printf("\n%d deleted",t->data);
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

/*struct node *deleteattail()
{
	struct node *t=head;
	if (head)//terminates at head equals to NULL
	{
		if(head->link)
		{
			head=head->link;
			printf("\n%d deleted",t->data);
			free(t);
		}
		else
		{
			printf("\n%d deleted",t->data);
			free(t);
			head=NULL;
			tail=NULL;
		}
	}
	else
	{
		printf("\nlinked list is empty");
	}
}*/

struct node *reverse()
{
	struct node *previous=NULL, *current=NULL, *post=head;
	while(post)//post not equals to NULL
	{
		previous=current;
		current=post;
		post=current->link;
		current->link=previous;
	}
	head=current;
}

struct node *deleteattail()
{
	struct node *t=head;
	if(head)
	{
		if(head->link)
		{
			while(t->link!=tail)
			{
				t=t->link;
			}
			printf("%d deleted\n",t->data);
			free(tail);
			tail=t;
		}
	}
	else
	{
		printf("\n linked list is empty");
	}
}

void main()
{
	int i=0;
	for(int i=0; i<4; i++)
	{
		insert();
	}
	
	traverse();
	delete();
	traverse();
	insertbetween(2);
	traverse();
	insertathead();	
	traverse();
	printf("\nreverse after");
	reverse();
	traverse();
	deleteattail();

}
