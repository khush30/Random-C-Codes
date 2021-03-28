#include"stackArrayLib.h"

//creates an empty stack using the above stack
arrayStackType createArrStack(int x)
{
    arrayStackType temp;
    temp.size = x;
    temp.top = -1;
    temp.list = (int*)malloc(x*sizeof(int));
    return temp;
}

//pushes/adds element onto the stack
void pushArr(arrayStackType *head , int element)
{
    if(head->top < head->size -1)
    {
        head->top += 1;
        (head->list)[head->top] = element;
    }    
}

//pops/deletes element from the stack and returns the popped element
int popArr(arrayStackType *head)
{
    int temp;
    if(head->top >= 0)
    {
        temp = head->list[head->top];
        head->top -= 1;
    }
    else
        temp = 9999;
    return temp;
}

//displays all the stack elements in top to bottom manner
void displayArr(arrayStackType head)
{
    if(head.top >= 0)
    {
        int i;
        for(i = head.top ; i >=0 ; i--)
            printf("\t\t%d\n",head.list[i]);
        printf("\n");
    }
}

//destroys the stack
void destroyArrStack(arrayStackType *head)
{
    head->size = 0;
    head->top = -1;
    free(head->list);
}