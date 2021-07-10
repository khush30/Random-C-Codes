#include"linkedList.h"

void main()
{
	int choice,Elements=0,newElmt;
	char *go;
	list_type unorderedList;
	orderedList=NULL,unorderedList=NULL;
	while(1)
	{
		new();
		printf("\tEnter your choice please\n\t\t1-> Add element at beginning\n\t\t2-> Add element at the end\n\t\t3-> Add element at given position\n\t\t4-> Delete the first element\n\t\t5-> Delete a particular element\n\t\t6-> Delete the last element\n\t\t7-> Display the list\n\t\t8-> Search for a number\n\t\t9-> Modify a particular number\n\t\t10->Exit\n\t");
		while(1)
		{
			scanf("%d",&choice);
			if(choice>0 && choice<11)
				break;
			printf("\tInvalid input! Select from the given menu\n\t");
		}
		switch(choice)
		{
			case 1:
				new();
				printf("\tEnter the element to be added:\t");
				scanf("%d",&newElmt);
				if(unorderedList==NULL)
				{
					node_ptr temp=(node_type*)malloc(sizeof(node_type));
					temp->data=newElmt;
					unorderedList=temp;
				}
				else
					unorderedList=add_at_beginning(unorderedList,newElmt);
				display(unorderedList);
				break;
			
			case 2:
				new();
				printf("\tEnter the element to be added:\t");
				scanf("%d",&newElmt);
				if(unorderedList==NULL)
				{
					node_ptr temp=(node_type*)malloc(sizeof(node_type));
					temp->data=newElmt;
					temp->next=NULL;
					unorderedList=temp;
				}
				else
					unorderedList=add_at_end(unorderedList,newElmt);
				display(unorderedList);
				break;
			
			case 3:
				new();
				printf("\tEnter the element to be added:\t");
				scanf("%d",&newElmt);
				if(unorderedList==NULL)
				{
					printf("\tThe list is empty! The element is added at the first position\n");
					node_ptr temp=(node_type*)malloc(sizeof(node_type));
					temp->data=newElmt;
					temp->next=NULL;
					unorderedList=temp;
				}
				else
				{
					unsigned int pos,count;
					printf("\tEnter the position at which to enter the element: ");
					scanf("%u",&pos);
					count=total_nodes(unorderedList);
					if(pos>count)
						printf("\tNumber of elements in the list are less than the position entered, so it is added at the end!\n");
					unorderedList=positional_insert(unorderedList,newElmt,pos);
				}
				display(unorderedList);
				break;
			
			case 4:
				new();
				if(unorderedList==NULL)
					printf("The list is already empty!\n");
				else
				{
					unorderedList=delete_start(unorderedList);
					if(unorderedList!=NULL)
						display(unorderedList);
					else
						printf("\tThe list is now empty!\n");
				}
				break;
			
			case 5:
				new();
				if(unorderedList==NULL)
					printf("The list is already empty!\n");
				else
				{
					int element,pos;
					printf("\tEnter the element to be deleted: ");
					scanf("%d",&element);
					pos=search(unorderedList,element);
					if(pos)
					{
						unorderedList=delete_element(unorderedList,pos);
						if(unorderedList!=NULL)
							display(unorderedList);
						else
							printf("\tThe list is now empty!\n");
					}
					else
						printf("\tThe element is not present in the list\n");
				}
				break;
				
			case 6:
				new();
				if(unorderedList==NULL)
					printf("The list is already empty!\n");
				else
				{
					unorderedList=delete_end(unorderedList);
					if(unorderedList!=NULL)
						display(unorderedList);
					else
						printf("\tThe list is now empty!\n");
				}
				break;
				
			case 7:
				new();
				if(unorderedList!=NULL)
					display(unorderedList);
				else
					printf("\tThe list is empty!\n");
				break;
			
			case 8:
				new();
				if(unorderedList==NULL)
					printf("The list is empty!\n");
				else
				{
					int num,found_at;
					printf("\tEnter the number to be searched: ");
					scanf("%d",&num);
					found_at=search(unorderedList,num);
					if(found_at)
						printf("\tThe element is present at position: %d\n",found_at);
					else
						printf("\tThe element not found!\n");
				}
				break;	
			
			case 9:
				new();
				if(unorderedList==NULL)
					printf("The list is empty!\n");
				else
				{
					int num,found_at;
					printf("\tEnter the number to be searched: ");
					scanf("%d",&num);
					found_at=search(unorderedList,num);
					if(found_at)
					{
						int newValue;
						printf("\tEnter the new value to be put in place of %d: ",num);
						scanf("%d",&newValue);
						unorderedList=modify(unorderedList,found_at,newValue);
						display(unorderedList);
					}
					else
						printf("\tThe element id not in the list!\n");
				}
				break;
			
			case 10:
				new();
				printf("Thank you, bye!🤗\n");
				exit(0);
		}
		printf("\tEnter any character to continue:\t");
		scanf("%s",go);
	}
}
