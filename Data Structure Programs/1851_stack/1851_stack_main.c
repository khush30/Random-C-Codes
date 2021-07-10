#include"stack_functions.h"

void main()
{
	char choice,flag;
	stackType header;	header.start=NULL;
	header.count=0;
	do
	{
		system("clear");
		printf("\tEnter your choice\n\t\t1-> Push\n\t\t2-> Pop\n\t\t3-> Peek\n\t\t4-> Display\n\t\t5-> Exit\n\t");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':
				system("clear");
				int temp_data;
				printf("\tEnter your data:\t");
				scanf("%d",&temp_data);
				header=push(temp_data,header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
				
			case '2':
				system("clear");
				if(header.count==0)
					printf("\tThe list is already empty!\n");
				else
					header=pop(header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
				
			case '3':
				system("clear");
				if(header.count==0)
					printf("\tThe list is empty!\n");
				else
					peek(header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
				
			case '4':
				system("clear");
				if(header.count==0)
					printf("\tThe list is empty!\n");
				else
					display(header);
				printf("\n\n\tEnter some value to continue:\t");
				scanf(" %c",&flag);
				break;
			
			case '5':
				break;
				
			default:
				printf("Invalid");
		}
	}while(choice!='5');
}
