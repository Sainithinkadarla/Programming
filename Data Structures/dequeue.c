#include<stdio.h>
#include<stdlib.h>

void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display_front();
void display_rear();

void main()
{
	// default values: ins_front=N;
	//				   	del_rear=N;
	//				 : ins_rear=-1;
	//				 : del_front=-1;
	int c,i,N=4,del_front=-1,ins_rear=-1,del_rear=N,ins_front=N;
	printf("%d %d",del_front,ins_rear);
	//printf("Enter the queue size : ");
	//scanf("%d",&N);
	int q[N];

void insert_front()
{
	if(ins_front!=0 && ins_front-1!=ins_rear)
	{
		int x;
		printf("\nenter element to insert: ");
		scanf("%d",&x);
		ins_front--;
		q[ins_front]=x;
		if(del_rear==N)
		{
			del_front--;
		}
	}
	else
	{
		printf("queue is full");
	}
}

void insert_rear()
{
	int x;
	if(ins_rear!=N-1 && ins_rear+1!=ins_front)
	{
		printf("\nenter element to insert: ");
		scanf("%d",&x);
		ins_rear++;
		q[ins_rear]=x;
		if(del_front==-1)
		{
			del_front++;
		}
	}
	else
	{
		printf("\nqueue is full");
	}
}


void display_front()
{
	if(ins_rear!=-1)
	{
		for(i=del_front;i<=ins_rear;i++)
		{
			printf("\t%d",q[i]);
		}
	}
	else
	{
		printf("\nqueue is empty");
	}
}

void display_rear()
{
        if(ins_front!=-1)
        {
                for(i=ins_front;i<=del_rear;i++)
                {
                        printf("\n%d",q[i]);
                }
        }
        else
        {
                printf("\nqueue is empty");
        }

}

void delete_front()
{
	if(ins_rear!=-1)
	{
		printf("\ndeleted element %d",q[del_front]);
		if(del_front==delete_rear)
		{
			del_front=ins_rear=-1;
			ins_front=del_rear=N;		
		}
		del_front++;
	}	
	else
	{
		printf("\nqueue is empty");
	}
}

void delete_rear()
{
	if(ins_front!=N)
	{
		printf("\ndeleted element %d",q[del_rear]);
		if(del_rear==del_front)
		{
			del_front=ins_rear=-1;
			ins_front=del_rear=N;		
		}
		del_front--;
	}	
	else
	{
		printf("\nqueue is empty");
	}
}
	
	display_front();
	display_rear();

}

