#include<stdio.h>
#include<stdlib.h>

typedef struct bstnode
{
	int data;
	struct bstnode *left;
	struct bstnode *right;
}bstnodetype;

typedef struct
{
	int count;
	int height;
	bstnodetype *root; 
}bstType;

void insertnode(bstType *,int);
void inorder(bstnodetype *);
void preorder(bstnodetype *);
void postorder(bstnodetype *);
//void displaytree(bsttype);
short int search(bstnodetype *,int,int *);
short int deletenode(bstType *,int);
int findheight(bstnodetype *);
