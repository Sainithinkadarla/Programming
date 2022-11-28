#include<stdio.h>
#include<stdlib.h>
void insert();
void delete();
void display();

void main()
{
	int c,N=4,ins,front=-1,rear=-1,cq[N];
	printf("enter the queue size: ");
	scanf("%d",&N);
	

void insert()
{
	if(front==0&&rear==N-1 || rear+1==front) 	
	{
		printf("\nqueue overflow");	
	}
	else
	{
		if(rear==-1)
		{
			front=rear=0;
		}
		else if(rear==N-1)
		{
			rear=0;
		}	
		else
		{	
			rear++;
		}
		printf("\nenter the element to insert: ");
		scanf("%d",&ins);
		cq[rear]=ins;
		printf("%d",rear);
	}
	
}
void delete()
{	
	int deleted;
	deleted=cq[front];
	if(front!=-1)
	{
		if(front==N-1)
		{
			front=0;		
		}	
		else if(front==rear)
		{
			front=rear=-1;
		}	
		else
		{
			front++;
		}
		printf("deleted element is %d",deleted);
	}	
	else
	{
		printf("\nqueue is empty");
	}
	printf("front=%d         rear=%d",front,rear);
}
void display()
{
	int i,j;
	if(front==-1&&rear==-1)
	{	
	printf("\nqueue is empty");
	}
	if(front>rear)
	{	
		for(j=0;j<=rear;j++)
			printf("\t%d",cq[j]);
		for(i=front;i<N;i++)
			printf("\t%d",cq[i]);
	}	
	else
	{
		for(i=front;i<=rear;i++)
			printf("\t %d",cq[i]);		
	}
	printf("\n");
}
	while(1)
	{
		printf("\n\nchoose a operation\n1. insert\n2. delete\n3. Display\n4. Exit\n");
		scanf("%d",&c);
		switch (c)
		{
		case 1:
			insert();
			break;
		case 2:
			delete();
			break;
		case 3:
			display();
			break;
		case 4:
			exit(0);
		}
	}

}

