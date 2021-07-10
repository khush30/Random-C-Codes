#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	int data;
	struct node *next;
}nodeType;

typedef struct
{
	int count;
	nodeType *start;
}stackType;

stackType push(int temp_data,stackType start);
stackType pop(stackType header,int *temp_data);
void peek(stackType header);
void display(stackType header);
