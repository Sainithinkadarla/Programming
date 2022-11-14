#include<stdio.h>
#include<stdlib.h>

void linear_search();

void main()
{

int k,pointer=0,array[5]={1,3,6,83,2};


int linear_search(int key)
{
	if(pointer==5)	
	{
		printf("element not found");
		return 0;
	}
	else
	{
		if(key==array[pointer])
		{
			printf("element found");
		}
		else
		{	
			pointer++;
			linear_search(key);

		}
	}
	
}
printf("enter element to search: ");
scanf("%d",&k);
linear_search(k);
}
