#include<stdio.h>
#include<stdlib.h>


struct node 
{
    int data;
    struct node *left_child, *right_child;
}*root=NULL,*t;

struct node *getnode(int data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->left_child=t->right_child=NULL;
    return t;
}

int postorder[7]={1,3,2,5,7,6,4};
int inorder[7]={1,2,3,4,5,6,7};

int s=6;

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
    s--;
    temp->right_child=build(po, io, index+1, end);
    temp->left_child=build(po, io, start, index-1);  
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

void post_order(struct node *root)
{
    if(root)
    {
        post_order(root->left_child);
        post_order(root->right_child);
        printf("\t%d",root->data);
    }
}

void main()
{
    build(postorder, inorder, 0, 6 );
    printf("\nIn order\n");
    in_order(root);
    printf("\nPost order\n");
    post_order(root);
}