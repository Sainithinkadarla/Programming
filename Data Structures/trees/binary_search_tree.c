#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left_child, *right_child;
}*getnode, *t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left_child=t->right_child=NULL;
    return t;
}

void insert()
{
    int data;
    printf("\nEnter the data to insert: ");\
    scanf("%d",&data);
    t=getnode(data);
    if(!root)
    {
        root=t;
    }
    if(root->data)
}

void main()
{

}