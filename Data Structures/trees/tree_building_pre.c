#include<stdio.h>
#include<stdlib.h>

char inorder[]="abcdefg";
char preorder[]="dbacfeg";

struct node
{
    char data;
    struct node *right_child;
    struct node *left_child;
} *root=NULL, *t;

struct node *getnode(char data)
{
    t=(struct node *)malloc(sizeof(struct node));
    t->data=data;
    t->right_child=NULL;
    t->left_child=NULL;
    return t;
}

int i=0;
struct node *build(char inorder[], char preorder[], int i, int j)
{
    if(prefix[i]) 
    {
        t=getnode(preorder[i]);
        if(root)
        {
            printf("%c",preorder[i]);
            t->left_child=build(inorder,preorder, );
        }
        else
        {
            root=t;
        }    
    }
    return t;
}

struct node *test()
{
    int i;
    for (i=0; preorder[i]; i++)
    {
        printf("%c",preorder[i]);
    }
}

void main()
{
    test();
    build(0);
}