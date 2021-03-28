#include<stdio.h>
#include<stdlib.h>

//structure of a single node of the list
typedef struct node
{
    int data;
    struct node *next;
}nodeType;

/*structure of the stack head, where it stores 
    the count of total nodes,
    the address of the top node
*/
typedef struct
{
    int count;
    nodeType *top;
}linkedListStackType;

//to create an empty stack
linkedListStackType createLLStack();

//to push/add an element onto the stack
void pushLL(linkedListStackType* , int);

//to pop/delete an element from the stack
int popLL(linkedListStackType*);

//to display all the elements in the stack (top to bottom)
void displayLL(linkedListStackType);

//destroys the stack
void destroyLLStack(linkedListStackType*);