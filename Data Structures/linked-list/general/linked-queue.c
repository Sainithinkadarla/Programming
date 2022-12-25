#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct  node *link;
}*t, *front=NULL,*rear=NULL;


struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->link=NULL;
    return t;
}

struct node *enqueue()
{
    int data;
    printf("\nEnter the data to enqueue: ");
    scanf("%d",&data);
    t=getnode(data);
    if(front==NULL)
    {
        front=t;
    }
    else
    {
        rear->link=t;
    }
    rear=t;
}

struct node *dequeue()
{
    if(front)
    {
        t=front;
        front=front->link;
        printf("\n%d dequeued",t->data);
        free(t);
        if (!(front))
        {
            front=NULL;
            rear=NULL;
        }
    }
    else
    {
        printf("\nqueue is empty");
    }
}

struct node *display()
{
    t=front;
    if(t)
    {
        while(t)
        {
            printf("%d\t",t->data);
            t=t->link;
        }
    }
    else
        printf("\nqueue is empty");
}

void main()
{
    int c;
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