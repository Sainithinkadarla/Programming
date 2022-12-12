#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
}*t, *top=NULL;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->link=NULL;
    return t;
}

struct node *push()
{
    int data;
    printf("\nEnter data to push: ");
    scanf("%d",&data);
    t=getnode(data);
    t->link=top;
    top=t;
}

struct node *pop()
{
    
    if(top)
    {
        t=top;
        top=top->link;
        printf("\n\n%d popped",t->data);
        free(t);
    }
    else
    {
        printf("\nstack is empty");
    }
}

struct node *display()
{
    t=top;
    printf("\nStack\n--------------\n");
    while(t)
    {
        printf("\n%d",t->data);
        t=t->link;
    }
}
void main()
{
    int c;
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
