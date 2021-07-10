#include<stdio.h>
#include<stdlib.h>

typedef struct polynomial
{
	int coefficient;
	int exponent;
	struct polynomial *nextTerm;
}polynomialType;

void displayEquation(polynomialType *equation);
polynomialType* createEquation(int coef,int expo,polynomialType *equation);
polynomialType* add(polynomialType *equation1,polynomialType *equation2);
polynomialType* freeList(polynomialType *list);
