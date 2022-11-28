#include<stdio.h>
#include<stdlib.h>

int linearsearch(int k);


void main()
{
	int flag=0,key,n,arr[5]={1,23,54,34,67};
	n=sizeof(arr)/sizeof(arr[0]);
	printf("Enter the element to search: ");
	scanf("%d",&key);
	int linearsearch(int k)
	{
		int i,flag=0;
		for(i=0;i<=n-1;i++)
		{
			if(arr[i]==k)
			{
				flag=1;
			}
			}	
		if(flag==1)
		{
		printf("%d element found at %d",k,i);
		}
		else
		{
		printf("element not found");	
		}
	}
	linearsearch(key);	
}
