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
	nodeType *front;
	nodeType *rear;
}queueType;

void enqueue(int temp_data,queueType *start);
int dequeue(queueType *header);
void display(queueType header);
