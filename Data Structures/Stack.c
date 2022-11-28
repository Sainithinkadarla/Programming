#include<stdio.h>
#include<stdlib.h>
void push();
void pop();
void display();

void main()
{
int e,i,N,top=-1,c,s[N];
printf("\nenter the stack size : ");
scanf("%d",&N);

void push()
{
	if(top<N-1)
	{
		printf("\nEnter element to push: ");
		scanf("%d",&e);
		top++;
		s[top]=e;
	}
	else
	{
		printf("\nstack is full\n");
	}
}

void pop()
{	
	if(top!=-1)
	{
		printf("\n%d is popped",s[top]);
		top--;
	}
	else
	{
		printf("\nstack is empty");
	}
}

void display()
{
	if(top!=-1)
	{	
		for(i=top;i>-1;i--)
		{
			printf("\n%d",s[i]);
		}	
	}
	else
	{	
		printf("\nstack is empty\n");
	}	
}

while(1)
	{
		printf("\n\nchoose a operation\n1. Push\n2. Pop\n3. Display\n4. Exit\n: ");
		scanf("\n%d",&c);

		switch(c)
		{
			case 1 : push(); 
			break;
			case 2 : pop();
			break;
			case 3 : display(); 
			break;
			case 4 : exit(0);
			break; 
		}
	}
}

