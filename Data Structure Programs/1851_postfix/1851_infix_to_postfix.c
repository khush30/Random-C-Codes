#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct node
{
	char data;
	struct node *next;
}nodeType;

typedef struct
{
	int count;
	nodeType *start;
}stackType;

stackType push(char temp_data,stackType start);
stackType pop(stackType header,char *temp_data);
char peek(stackType header);

stackType push(char temp_data,stackType header)
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

stackType pop(stackType header,char *temp_data)
{
	nodeType *temp;
	temp=header.start;
	*temp_data=header.start->data;
	header.start=header.start->next;
	free(temp);
	header.count--;
	return header;
}

char peek(stackType header)
{
	return header.start->data;
}

short int convert(char infix[],char post[]);

short int convert(char infix[],char post[])
{
	short int i,j=0,flag=1,t_flag;
	stackType header;
	header.count=0;
	header.start=NULL;
	char temp='@';
	for(i=0;i<strlen(infix) && flag;i++)
	{
		if((infix[i]>='a' && infix[i]<='z') || (infix[i]>='A' && infix[i]<='Z') || (infix[i]>='0' && infix[i]<='9'))
			post[j++]=infix[i];
		else
		{
			switch(infix[i])
			{
				case '(':
					header=push(infix[i],header);
					break;
				case ')':
					if(header.count<1)
						flag=0;
					else
					{
						header=pop(header,&temp);
						while(temp!='(')
						{
							post[j++]=temp;
							header=pop(header,&temp);
						}
					}
					break;
				case '+':
					t_flag=1;
					do
					{
						if(header.count)
						{
							temp=peek(header);
							if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='^')
							{
								header=pop(header,&temp);
								post[j++]=temp;
							}
							else
								t_flag=0;
						}
						else
							t_flag=0;
					}while(t_flag);
					header=push(infix[i],header);
					break;
				case '-':
					t_flag=1;
					do
					{
						if(header.count)
						{
							temp=peek(header);
							if(temp=='+' || temp=='-' || temp=='*' || temp=='/' || temp=='^')
							{
								header=pop(header,&temp);
								post[j++]=temp;
							}
							else
								t_flag=0;
						}
						else
							t_flag=0;
					}while(t_flag);
					header=push(infix[i],header);
					break;
				case '/':
					t_flag=1;
					do
					{
						if(header.count)
						{
							temp=peek(header);
							if(temp=='*' || temp=='/' || temp=='^')
							{
								header=pop(header,&temp);
								post[j++]=temp;
							}
							else
								t_flag=0;
						}
						else
							t_flag=0;
					}while(t_flag);
					header=push(infix[i],header);
					break;
				case '*':
					t_flag=1;
					do
					{
						if(header.count)
						{
							temp=peek(header);
							if(temp=='*' || temp=='/' || temp=='^')
							{
								header=pop(header,&temp);
								post[j++]=temp;
							}
							else
								t_flag=0;
						}
						else
							t_flag=0;
					}while(t_flag);
					header=push(infix[i],header);
					break;
				case '^':
					t_flag=1;
					do
					{
						if(header.count)
						{
							temp=peek(header);
							if(temp=='^')
							{
								header=pop(header,&temp);
								post[j++]=temp;
							}
							else
								t_flag=0;
						}
						else
							t_flag=0;
					}while(t_flag);
					header=push(infix[i],header);
					break;
				default:
					flag=0;
			}
		}
	}
	while(header.count)
	{
		header=pop(header,&temp);
		if(temp!='(' && temp!=')')
			post[j++]=temp;
	}
	post[j]='\n';
	return flag;	
}

void main()
{
	char choice;
	do
	{
		system("clear");
		short int flag;
		int result;
		char infixExpression[20],postExpression[20];
		printf("\tEnter the infix expression to be translated to postfix:\n\t\t");
		scanf("%s",infixExpression);
		flag=convert(infixExpression,postExpression);
		if(flag)
			printf("\tPostfix Expression done successfully!\n\t\t %s",postExpression);
		else
			printf("\tPostfix expression entered is incorrect!\n");
		printf("\n\n\tEnter 'n' to exit:\t");
		scanf(" %c",&choice);
	}while(choice != 'n');
	system("clear");
}
