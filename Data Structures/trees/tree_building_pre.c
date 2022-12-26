#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node *left_child, *right_child;
}*root,*t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left_child=t->right_child=NULL;
    return t;
}

int preorder[7]={4,2,1,3,6,5,7};
int inorder[7]={1,2,3,4,5,6,7};

int s=0;

struct node *build(int po[], int io[], int start, int end)
{
    int index;
    if(start > end)
    {
        return NULL;
    }

    struct node *temp=getnode(po[s]);
    if(!root)
    {
        root=temp;
    }

    for(int i=start; i<=end; i++)
    {
        if(po[s]==io[i])
        {
            index=i;
            break;
        }
    }
    s++;
    temp->left_child=build(po, io, start, index-1);  
    temp->right_child=build(po, io, index+1, end);
    return temp;
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
}

void main()
{
    build(preorder, inorder, 0, 6 );
    printf("\nIn order\n");
    in_order(root);
    printf("\nPre order\n");
    pre_order(root);
}