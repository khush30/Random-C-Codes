#include<stdlib.h>
#include<stdio.h>

typedef struct
{
    int top;
    int *list;
    int size;
}arrayStackType;

//creates an empty stack using the above stack
arrayStackType createArrStack();

//pushes/adds element onto the stack
void pushArr(arrayStackType* , int);

//pops/deletes element from the stack and returns the popped element
int popArr(arrayStackType*);

//displays all the stack elements in top to bottom manner
void displayArr(arrayStackType);

//destroys the stack
void destroyArrStack(arrayStackType*);