#include"bstfunctions.h"

void insertnode(bstType *tree,int newdata)									//insert element in ascending order, following the bst property
{																			//left < root < right
	int i=0;
	short int flag=1;
	bstnodetype *newnode=(bstnodetype*)malloc(sizeof(bstnodetype));			//allocating memory for the new element
	newnode->data=newdata;
	newnode->left=NULL;
	newnode->right=NULL;
	if(tree->root==NULL)													//if tree empty, element inserted at the root
		tree->root=newnode;
	else																	//else, find it's correct position
	{
		bstnodetype *parent,*temp=tree->root;
		while(temp!=NULL && flag)													
		{																	//counter to keep track of the level at which the new element is put
			i++;
			parent=temp;
			if(temp->data > newdata)										//to find the correct position to enter the data
				temp=temp->left;
			else if(temp->data < newdata)
				temp=temp->right;
			else
				flag=0;
		}
		
		if(flag)											//if no duplicate, insert the data
		{
			if(parent->data > newdata)
				parent->left=newnode;
			else
				parent->right=newnode;
		}
		else																//else, free the allocated space for the newnode
		{
			printf("\n\tDuplicates not allowed!\n");
			tree->count--;													//made so that further chenges do not affect the original values
			i=tree->height;
			free(newnode);
		}
	}
	if(tree->height < i)													//if level the new node is than previous height, make it the height
		tree->height=i;
	tree->count++;															//increase the count of elements
}

void inorder(bstnodetype *root)												//left root right
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("\t%d",root->data);
		inorder(root->right);
	}
}

void postorder(bstnodetype *root)											//left right root
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("\t%d",root->data);
	}
}

void preorder(bstnodetype *root)											//root left right
{
	if(root!=NULL)
	{
		printf("\t%d",root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

short int search(bstnodetype *root,int value,int *level)					//returns 1 if found, and also the level at which the element is found
{
	short int flag=0;
	*level=-1;
	bstnodetype *temp=root;
	while(temp!=NULL && !flag)
	{
		if(temp->data == value)
			flag=1;
		else if(temp->data > value)
			temp=temp->left;
		else
			temp=temp->right;
		(*level)++;
	}
	return flag;
}

short int deletenode(bstType *tree,int value)
{
	bstnodetype *parent=NULL,*temp=tree->root;
	short int flag=0,left;
	while(temp!=NULL && !flag)												//to check if element is present
	{
		if(temp->data == value)
			flag=1;
		else
		{
			parent=temp;
			if(temp->data > value)											//to see where the data lies, left or right
			{
				left=1;
				temp=temp->left;
			}
			else
			{
				left=0;
				temp=temp->right;
			}
		}
	}
	if(flag)																//if the data is found
	{
		if(temp->left==NULL && temp->right==NULL)								//if the node has no children, delete the node
		{
			free(temp);
			if(parent==NULL)													//if that was the root, make root NULL
			{
				tree->root=NULL;
				tree->height=-1;
			}
			else																//else make the pointer pointing to the deleted node NULL
				if(left)
					parent->left=NULL;
				else
					parent->right=NULL;
		}																		//else, if it has only child, replace it with the child
		else if(temp->left==NULL && temp->right!=NULL)
		{
			if(parent==NULL)
				tree->root=temp->right;
			else
				if(left)														
					parent->left=temp->right;
				else
					parent->right=temp->right;
			temp->right=NULL;
			free(temp);
		}
		else if(temp->left!=NULL && temp->right==NULL)
		{
			if(parent==NULL)
				tree->root=temp->left;
			else						
				if(left)
					parent->left=temp->left;
				else
					parent->right=temp->left;
			temp->left=NULL;
			free(temp);
		}
		else																//else, if it has both children
		{
			bstnodetype *successor=temp->right;
			parent=NULL;
			while(successor->left != NULL)										//find its successor node
			{
				parent=successor;
				successor=successor->left;
			}
			temp->data=successor->data;											//replace it with the successor element
			if(parent==NULL)													//delete the successor following the above procedures
				if(successor->right != NULL)
					temp->right=successor->right;
				else
					temp->right=NULL;
			else
				if(successor->right != NULL)
					parent->left=successor->right;
				else
					parent->left=NULL;
			free(successor);
		}
	}
	return flag;
}

int findheight(bstnodetype *root)											//recursive function to find the height of the tree
{
	int tempLeft,tempRight,temp=-1;
	if(root!=NULL)															//finds the height of left and right sub trees, and returns the higher
	{
		tempLeft=findheight(root->left);									
		tempRight=findheight(root->right);
		if(tempLeft > tempRight)
			temp=tempLeft+1;
		else
			temp=tempRight+1;
	}
	return temp;
}
