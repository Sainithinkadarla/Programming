#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right_child, *left_child;
}*root=NULL,*t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->right_child=NULL;
    t->left_child=NULL;
    return t;
}

int leaves(struct node *root)
{
    if(root->right_child && root->left_child)
    {
        return leaves(root->left_child)+leaves(root->right_child);
    }
    else
    {
        return 1;
    }
}

int nodes(struct node *root)
{
    if(root)
    {
        return 1+nodes(root->left_child)+nodes(root->right_child);
    }
    else
    {
        return  0;
    }
}

void main()
{
    root=getnode(100);
    root->right_child=getnode(200);
    root->right_child->left_child=getnode(400);
    root->left_child=getnode(300);
    root->left_child->right_child=getnode(500);

    printf("%d",leaves(root));
    printf("%d",nodes(root));
}