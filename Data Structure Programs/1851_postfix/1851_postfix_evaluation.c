/*

assumption:
			1. expression to be evaluated will have only one digit numbers
			2. it will only perform integer operations, no float

*/
#include"stack_functions.h"
#include<string.h>

short int postEvaluation(char expression[],int *finalValue);
stackType operation(stackType header,char operator,short int *flag);

stackType operation(stackType header,char operator,short int *flag)
{
	int operand1,operand2,result=1;
	header=pop(header,&operand2);
	header=pop(header,&operand1);
	switch(operator)
	{
		case '+':
			header=push(operand1+operand2,header);
			break;
		case '-':
			header=push(operand1-operand2,header);
			break;
		case '*':
			header=push(operand1*operand2,header);
			break;
		case '/':
			header=push(operand1/operand2,header);
			break;
		case '^':
			for(int i=0;i<operand2;i++)
				result*=operand1;
			header=push(result,header);
			break;
		default:
			*flag=0;
	}
	return header;
}

short int postEvaluation(char expression[],int *finalValue)
{
	short int flag=1,i,temp;
	stackType header;
	header.count=0;
	header.start=NULL;
	for(i=0;i<strlen(expression);i++)
	{
		if(expression[i]>47 && expression[i]<58)
		{
			temp=expression[i]-48;
			header=push(temp,header);
		}
		else
		{
			if(header.count<2)
			{
				flag=0;
				break;
			}
			else
				header=operation(header,expression[i],&flag);
		}
	}
	if(flag && header.count==1)
		*finalValue=header.start->data;
	else
		flag=0;
	return flag;
}

void main(void)
{
	char choice;
	do
	{
		system("clear");
		short int flag;
		int result;
		char postExpression[20];
		printf("\tEnter the postfix expression to be evaluated:\n\t\t");
		scanf("%s",postExpression);
		flag=postEvaluation(postExpression,&result);
		if(flag)
			printf("\tPostfix Expression evaluation done successfully!\n\tResult= %d",result);
		else
			printf("\tPostfix expression entered is incorrect!\n");
		printf("\n\n\tEnter 'n' to exit:\t");
		scanf(" %c",&choice);
	}while(choice != 'n');// || choice != 'N');
	system("clear");
}
