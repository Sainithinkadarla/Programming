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
/*int i=0;
int d[5]={4,2,5,1,6,14,8};*/
struct node *insert(struct node *funroot, int data)
{
    struct node *temp=getnode(data);
    if(funroot)
    {
        funroot=temp;
    }
    else if(data<=funroot->data)
    {
        return insert(root->right_child,data);
    }
    if(data>funroot->data)
    {
        return insert(root->left_child,data);
    }
    
    return t;
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