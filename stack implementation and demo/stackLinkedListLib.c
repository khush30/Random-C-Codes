#include"stackLinkedListLib.h"

//to create an empty stack
linkedListStackType createLLStack()
{
    linkedListStackType head;
    head.count = 0;
    head.top = NULL;
    return head;
}

//to push/add an element onto the stack
void pushLL(linkedListStackType *head , int element)
{
    nodeType *temp = (nodeType*) malloc(sizeof(nodeType));
    temp->data = element;
    temp->next = NULL;
    if(head->count > 0)
        temp->next = head->top;
    head->top = temp;
    head->count += 1;
}

//to pop/delete an element from the stack
int popLL(linkedListStackType *head)
{
    int element;
    if(head->count == 0)
        element = -1;
    else
    {
        nodeType *temp;
        temp = head->top;
        element = temp->data;
        head->top = (head->top)->next;
        free(temp);
        head->count -= 1;
    }
    return element;
}

//to display all the elements in the stack (top to bottom)
void displayLL(linkedListStackType head)
{
    if(head.count > 0)
    {
        nodeType *ptr = head.top;
        while (head.top != NULL)
        {
            printf("\t\t%d\n",head.top->data);
            head.top = head.top->next;
        }
        printf("\n");
    }
}

//destroys the stack
void destroyLLStack(linkedListStackType *head)
{
    nodeType *ptr;
    while (head->top != NULL)
    {
        ptr = head->top;
        head->top = head->top->next;
        free(ptr);
    }
    head->count = 0;
}