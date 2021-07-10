#include"queue_functions.h"

void main()
{
	char choice,flag;
	queueType header;
	header.front=NULL;
	header.rear=NULL;
	header.count=0;
	do
	{
		system("clear");
		printf("\tEnter your choice\n\t\t1-> Push\n\t\t2-> Pop\n\t\t3-> Display\n\t\t4-> Exit\n\t");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':
				system("clear");
				int temp_data;
				printf("\tEnter your data:\t");
				scanf("%d",&temp_data);
				enqueue(temp_data,&header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
				
			case '2':
				system("clear");
				if(header.count==0)
					printf("\tThe list is already empty!\n");
				else
				{
					temp_data=dequeue(&header);
					printf("\tTop most element: %d\n\tSuccessfully popped\n",temp_data);
				}
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
				
			case '3':
				system("clear");
				if(header.count==0)
					printf("\tThe list is empty!\n");
				else
					display(header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
			
			case '4':
				break;
				
			default:
				printf("Invalid");
		}
	}while(choice!='4');
}
