#include"stack_functions.h"

stackType push(int temp_data,stackType header)
{
	nodeType *temp=(nodeType*)malloc(sizeof(nodeType));
	temp->data=temp_data;
	temp->next=NULL;
	if(header.count==0)
		header.start=temp;
	else
	{
		temp->next=header.start;
		header.start=temp;
	}
	header.count++;
	return header;
}

stackType pop(stackType header)
{
	nodeType *temp;
	temp=header.start;
	header.start=header.start->next;
	free(temp);
	header.count--;
	return header;
}

void display(stackType header)
{
	int i=header.count;
	while(header.start!=NULL)
	{
		printf("\t\t%d\t|\t%d\t|\n",i,header.start->data);
		header.start=header.start->next;
		i--;
	}
}

void peek(stackType header)
{
	printf("\tTotal elements:\t%d\n\n\t\tThe peek element is:\t%d\n",header.count,header.start->data);
}
