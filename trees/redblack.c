#include <stdio.h>
#include <stdlib.h>


enum{
    red,
    black
};

struct redblack
{
    struct node *left,*right;
    int data,color;
};

struct redblack *root =NULL;

struct redblack *createNode(int data){
    struct redblack *newNode = (struct redblack *)malloc(sizeof(struct redblack));
    newNode->color = red;
    newNode->data = data;
    newNode->right=newNode->left=NULL;
}
struct redblack *insertNode(int data){
    struct redblack *ptr,*lptr,*rptr;
    
}

