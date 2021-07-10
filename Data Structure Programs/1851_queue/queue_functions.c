#include"queue_functions.h"

void enqueue(int temp_data,queueType *header)
{
	nodeType *temp=(nodeType*)malloc(sizeof(nodeType));
	temp->data=temp_data;
	temp->next=NULL;
	if(header->count==0)
	{
		header->front=temp;
		header->rear=temp;
	}
	else
	{
		header->rear->next=temp;
		header->rear=header->rear->next;
	}
	header->count++;
}

int dequeue(queueType *header)
{
	int tempData=header->front->data;
	nodeType *temp=header->front;
	header->front=header->front->next;
	free(temp);
	header->count--;
	return tempData;
}

void display(queueType header)
{
	nodeType *temp=header.front;
	printf("\n\t\t");
	while(temp->next!=NULL)
	{
		printf("%d <-- ",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
}
