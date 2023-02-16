#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left_child, *right_child;
<<<<<<< HEAD
}*root=NULL, *t;
=======
}*root=NULL;
>>>>>>> fe423a722919a3ded19971d7a9b618e3f3be8bd2

struct node *getnode(int data)
{
    struct node *t;
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left_child=t->right_child=NULL;
    return t;
}

struct node *insert(struct node *funroot, int data)
{
<<<<<<< HEAD
    if(!root)
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
=======
    struct node *temp=getnode(data);
    if(!funroot)
    {
        funroot=temp;
    }

    else if(data<funroot->data)
    {
        funroot->left_child=insert(funroot->left_child,data);
    }
    else if(data>funroot->data)
    {
        funroot->right_child=insert(funroot->right_child,data);
    }
        
    return funroot;
}

void in_order(struct node *root)
{
    if(root)
    {
        in_order(root->left_child);
        printf("\t%d",root->data);
        in_order(root->right_child);
    }
}

void pre_order(struct node *root)
{
    if(root)
    {
        printf("\t%d",root->data);
        pre_order(root->left_child);
        pre_order(root->right_child);
    }
>>>>>>> fe423a722919a3ded19971d7a9b618e3f3be8bd2
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
<<<<<<< HEAD
=======
    printf("\nPre order\n");
    pre_order(root);
    printf("\nin order\n");
    in_order(root);
>>>>>>> fe423a722919a3ded19971d7a9b618e3f3be8bd2
}