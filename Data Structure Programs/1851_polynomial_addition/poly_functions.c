#include"poly_functions.h"

void displayEquation(polynomialType *equation)
{
	polynomialType *temp=equation;
	printf("\n\t\t%d x^",temp->coefficient);
	if(temp->exponent < 0)
		printf("(%d)",temp->exponent);
	else
		printf("%d",temp->exponent);
	temp=temp->nextTerm;
	while(temp!=NULL)
	{
		if(temp->coefficient >= 0)
			printf(" +");
		printf(" %d x^",temp->coefficient);
		if(temp->exponent < 0)
			printf("(%d)",temp->exponent);
		else
			printf("%d",temp->exponent);
		temp=temp->nextTerm;
	}
	printf("\n\t");
}

polynomialType* createEquation(int coef,int expo,polynomialType *equation)
{
	polynomialType *prev=NULL,*cur=equation,*new;
	new=(polynomialType*)malloc(sizeof(polynomialType));
	new->coefficient=coef;
	new->exponent=expo;
	if(equation==NULL)
		equation=new;
	else
	{
		while(cur!=NULL && cur->exponent > expo)
		{
			prev=cur;
			cur=cur->nextTerm;
		}
		if(cur!=NULL && cur->exponent == expo)
			cur->coefficient+=coef;
		else
		{
			if(prev==NULL)
			{
				new->nextTerm=cur;
				equation=new;
			}
			else
			{
				prev->nextTerm=new;
				new->nextTerm=cur;
			}
		}
	}
	return equation;
}

polynomialType* add(polynomialType *equation1,polynomialType *equation2)
{
	polynomialType *temp1=equation1,*temp2=equation2,*result=NULL,*new,*end;
	while(temp1!=NULL && temp2!=NULL)
	{
		new=(polynomialType*)malloc(sizeof(polynomialType));
		if(temp1->exponent == temp2->exponent)
		{
			new->coefficient=temp1->coefficient+temp2->coefficient;
			new->exponent=temp1->exponent;
			temp1=temp1->nextTerm;
			temp2=temp2->nextTerm;
		}
		else if(temp1->exponent > temp2->exponent)
		{
			new->coefficient=temp1->coefficient;
			new->exponent=temp1->exponent;
			temp1=temp1->nextTerm;
		}
		else
		{
			new->coefficient=temp2->coefficient;
			new->exponent=temp2->exponent;
			temp2=temp2->nextTerm;
		}
		new->nextTerm=NULL;
		if(result==NULL)
		{
			result=new;
			end=result;
		}
		else
		{
			end->nextTerm=new;
			end=end->nextTerm;
		}
	}
	if(temp1!=NULL)
		end->nextTerm=temp1;
	else if(temp2!=NULL)
		end->nextTerm=temp2;
	return result;
}

polynomialType* freeList(polynomialType *list)
{
	polynomialType *temp;
	while(list!=NULL)
	{
		temp=list;
		list=list->nextTerm;
		free(temp);
	}
	return NULL;
}
