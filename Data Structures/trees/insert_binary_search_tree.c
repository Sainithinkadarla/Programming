#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right_child, *left_child;
} *root, *t;

