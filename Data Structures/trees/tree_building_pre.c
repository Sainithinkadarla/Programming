#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left_child, *right_child;
}*root=NULL, *t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left_child=t->right_child=NULL;
    return t;
}

struct node *insert(struct node *funroot, int data)
{

    struct node *temp=getnode(data);
    if(!root)
    {
        funroot=temp;
    }
    if(data<=funroot->data)
    {
        temp->left_child=insert(root->left_child,data);
    }
    if(data>funroot->data)
    {
        temp->right_child=insert(root->right_child,data);
    }
    
    return temp;
}

void main()
{
    root=insert(root,7);
    root=insert(root,1);
    root=insert(root,2);
    root=insert(root,3);
    root=insert(root,17);
    root=insert(root,11);
    root=insert(root,18);
    root=insert(root,27);
}