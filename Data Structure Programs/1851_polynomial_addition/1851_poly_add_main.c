#include"poly_functions.h"

int main()
{
	int coef,expo,i,flag;
	char choice,m;
	polynomialType *equation1=NULL,*equation2=NULL,*result=NULL;
	do
	{
		system("clear");
		printf("\tEnter your choice\n\t\t1-> Add two equations\n\t\t2-> Exit\n\t");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':
				do
				{
					system("clear");
					printf("\t\t\tEquation 1\n");
					printf("\t\tEnter the coefficient:\t");
					scanf("%d",&coef);
					printf("\t\tEnter the exponent:\t");
					scanf("%d",&expo);
					equation1=createEquation(coef,expo,equation1);
					displayEquation(equation1);
					printf("\n\n\tDo you wanna add another term?\n\t\tEnter 0 to stop:\t");
					scanf(" %c",&flag);
				}while(flag!='0');
				do
				{
					system("clear");
					printf("\t\t\tEquation 2\n");
					printf("\t\tEnter the coefficient:\t");
					scanf("%d",&coef);
					printf("\t\tEnter the exponent:\t");
					scanf("%d",&expo);
					equation2=createEquation(coef,expo,equation2);
					displayEquation(equation2);
					printf("\n\n\tDo you wanna add another term?\n\t\tEnter 0 to stop:\t");
					scanf(" %c",&flag);
				}while(flag!='0');
				result=add(equation1,equation2);
				system("clear");
				printf("\t");
				displayEquation(equation1);
				printf("\t+\t");
				displayEquation(equation2);
				printf("\t=\t");
				displayEquation(result);
				scanf(" %c",&m);
				break;
			case '2':
				break;
			default:
				printf("\tInvalid\n");
		}
		equation1=freeList(equation1);
		equation2=freeList(equation2);
		result=freeList(result);
	}while(choice!='3');
}
