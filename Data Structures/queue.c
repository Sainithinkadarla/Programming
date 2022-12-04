#include<stdio.h>
#include<stdlib.h>
void enqueue();
void dequeue();
void display();

void main()
{
int e,i,N,front=-1,rear=-1,c;
printf("\nenter the queue size : ");
scanf("%d",&N);
int q[N];
void enqueue()
{
	if(rear<N-1)
	{
		printf("\nEnter element to enqueue: ");
		scanf("%d",&e);
		rear++;
		q[rear]=e;
		if(front==-1)
			front++;
	}
	else
	{
		printf("\nqueue is full\n");
	}
}

void dequeue()
{	
	if(rear!=-1)
	{
		printf("\n%d is dequeued",q[front]);
		if(front==rear)
			front=rear=-1;	
		front++;
	}
	else
	{
		printf("\nqueue is empty");
	}
}

void display()
{
	if(rear!=-1)
	{	
		for(i=front;i<=rear;i++)
		{
			printf("\n%d",q[i]);
		}	
	}
	else
	{	
		printf("\nqueue is empty\n");
	}	
}

while(1)
	{
		printf("\n\nchoose a operation\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n: ");
		scanf("\n%d",&c);

		switch(c)
		{
			case 1 : enqueue(); 
			break;
			case 2 : dequeue();
			break;
			case 3 : display(); 
			break;
			case 4 : exit(0);
			break; 
		}
	}
}

