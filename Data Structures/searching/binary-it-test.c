//This code is for understanding purpose

#include<stdio.h>
void main()
{
    int mid, key, arr[5]={23,25,28,36,43}, l=0, r=4, result=-1,i=1;
    printf("Enter the element to search: ");
    scanf("%d",&key);
printf("Enter the element to search: ");
    while(r>=l)
    {
        printf("\n\n%d     START",i);
        printf("\n  at start     r=%d    mid=%d   l=%d",r,mid,l);
        mid = (l+(r-1))/2;
        if(key==arr[mid])
        {
            printf("        %d element is found at %d",key,mid);
                result=1;
                break;
        }
        else if (key>arr[mid])
        {
            printf("\n  greater  r=%d    mid=%d   l=%d",r,mid,l);
            l=mid+1;
            printf("\n  post     r=%d    mid=%d   l=%d",r,mid,l);
        }
        else
        {
            printf("\nlesser  r=%d    mid=%d   l=%d",r,mid,l);
            r=mid-1;
            printf("\npost  r=%d    mid=%d   l=%d",r,mid,l);
        }
        if(i==7)
        {
            break;
        }
        i+=1;
    
    }
    if (result==1)
    {
        printf("\n%d element is found at %d",key,mid);
    }
    else
    {
        printf("\nelement not found");
    }
    
}