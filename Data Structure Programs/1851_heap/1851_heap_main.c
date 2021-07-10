#include<stdlib.h>
#include<stdio.h>
#include"heapFunctions.h"
#define MAX 50

void main()
{
	int n=0,nodes[MAX],i,j;
	char choice,cont;
	system("clear");
	printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\t\tEnter the initial total number of nodes:\t");
	scanf("%d",&n);
	printf("\n\n\tEnter the elements:\n");
	for(i=0;i<n;i++)
	{
		printf("\t\t");
		scanf("%d",&nodes[i]);
	}
	heapcreate(nodes,n);
	do
	{
		system("clear");
		printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
		printf("\tEnter your choice:\n\t\t1-> Display the max heap\n\t\t2-> Insert element\n\t\t3-> Delete element\n\t\t4-> Replace\n\t\t5-> Sort ascending and exit\n\t\t6-> Exit\n\t");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':
				system("clear");
				printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
				if(n)
				{
					if(n<16)
						display(nodes,n);
					else
						printf("\n\tCannot display graphically, as it might look distorted!\n\n");
					for(i=0;i<n;i++)
						printf("\t%d",nodes[i]);
					printf("\n");
				}
				else
					printf("\tNo elements in the heap tree\n");
				break;
			case '2':
				system("clear");
				printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
				printf("\tEnter the element to be inserted:\t");
				scanf("%d",&nodes[n]);
				reheapup(nodes,n);
				n++;
				break;
			case '3':
				system("clear");
				printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
				int value;
				char option;
				if(n)
				{
					do
					{
						printf("\tEnter you choice:\n\t\t1-> Delete the root(Max element)\n\t\t2-> Delete a particular element\n\t");
						scanf(" %c",&option);
						switch(option)
						{
							case '1':
								deleteRoot(nodes,&n);
								break;
							case '2':
								printf("\n\n\tEnter the value to be deleted:\t");
								scanf("%d",&value);
								deleteElement(nodes,value,&n);
								break;
							default:
								printf("\n\n\t\tInvalid choice!!!\n\n");
						}
					}while(option!='1' && option!='2');
				}
				else
					printf("\tNo elements in the heap tree\n");
				break;
			case '4':
				system("clear");
				printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
				if(n)
				{	
					short int flag=1;
					printf("\tEnter the element to be replaced:\t");
					scanf("%d",&j);
					for(i=0;i<n && flag;i++)
						if(nodes[i]==j)
							flag=0;
					if(!flag)
					{
						printf("\tEnter the new element:\t");
						scanf("%d",&value);
						replace(nodes,n,i-1,value);
					}
					else
						printf("\n\t%d is not present in the tree!\n",j);
				}
				else
					printf("\tNo elements in the heap tree\n");
				break;
			case '5':
				system("clear");
				printf("\tThis program is to perform basic operations on a MAX HEAP BINARY TREE\n\n\n");
				if(n)
				{	heapSort(nodes,n);
					if(n<16)
						display(nodes,n);
					else
						printf("\n\tCannot display graphically, as it might look distorted!\n\n");
					for(i=0;i<n;i++)
						printf("\t%d",nodes[i]);
					printf("\n");
					printf("\n\tEnter any character to exit:\t");
					scanf(" %c",&cont);
					system("clear");
					choice='6';
				}
				else
					printf("\tNo elements in the heap tree\n");
				break;
			case '6':
				system("clear");
				break;
			default:
				printf("\n\n\t\tInvalid choice!");
		}
		if(choice!='6')
		{
			printf("\n\tEnter any character to continue:\t");
			scanf(" %c",&cont);
		}
	}while(choice!='6');
}
