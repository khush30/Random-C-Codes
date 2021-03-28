#include"functionLib.h"
#include<unistd.h>
#include<string.h>

void implementationLL()
{
    linkedListStackType head = createLLStack();
    int element;
    char ch;
    while(1)
    {
        /*
            will only be terminated if exit option selected
        */
        system("clear");
        printf("\tEnter your choice\n");
        printf("\t\t1 -> Push\n\t\t2 -> Pop\n\t\t3 -> Display all elements\n\t\t4 -> Show top element\n\t\t5 -> Exit\n\t");
        scanf(" %c",&ch);
        printf("\n\n\n");
        switch(ch)
        {
            case '1':
                printf("\tEnter the element to be pushed: ");
                scanf("%d",&element);
                pushLL(&head , element);
                sleep(2);
                break;

            case '2':
                if(head.count > 0)
                {
                    element = popLL(&head);
                    printf("\t%d successfully popped\n",element);
                }    
                else
                    printf("\tNo elements to be popped\n");
                sleep(2);
                break;

            case '3':
                printf("\tElements in the stack (top to bottom) are:\n");
                displayLL(head);
                sleep(2);
                break;

            case '4':
                if(head.count > 0)
                    printf("\tThe top element is :\t%d\n",(head.top)->data);
                else
                    printf("\tNo elements in the stack\n");
                sleep(2);
                break;

            case '5':
                destroyLLStack(&head);
                sleep(2);
                break;

            default:
                printf("\n\t\tInvalid choice!!\n");
                sleep(2);
        }
        if(ch == '5')
            break;
    }
}

void implementationArr()
{
    arrayStackType head;
    int element , max;
    system("clear");
    printf("\tEnter a maximum size the stack should take for demo purpose\n\t\t");
    //max value needed coz its based on arrays, and arrays need to be initialised before using them
    scanf("%d",&max);
    head = createArrStack(max);
    char ch;
    while(1)
    {
        /*
            will only be terminated if exit option selected
        */
        system("clear");
        printf("\tEnter your choice\n");
        printf("\t\t1 -> Push\n\t\t2 -> Pop\n\t\t3 -> Display all elements\n\t\t4 -> Show top element\n\t\t5 -> Exit\n\t");
        scanf(" %c",&ch);
        printf("\n\n\n");
        switch(ch)
        {
            case '1':
                if(head.top < head.size - 1)
                {
                    printf("\tEnter the element to be pushed: ");
                    scanf("%d",&element);
                    pushArr(&head , element);
                }
                else
                    printf("\n\t\tStack overflow!\n");
                sleep(2);
                break;

            case '2':
                if(head.top >= 0)
                {
                    element = popArr(&head);
                    printf("\t%d successfully popped\n",element);
                }
                else
                    printf("\tNo elements to be popped\n");
                sleep(2);
                break;

            case '3':
                printf("\tElements in the stack (top to bottom) are:\n");
                displayArr(head);
                sleep(2);
                break;

            case '4':
                if(head.top >= 0)
                    printf("\tThe top element is :\t%d\n",head.list[head.top]);
                else
                    printf("\tNo elements in the stack\n");
                sleep(2);
                break;

            case '5':
                sleep(2);
                destroyArrStack(&head);
                break;

            default:
                printf("\n\t\tInvalid choice!!\n");
                sleep(2);
        }
        if(ch == '5')
            break;
    }
}


/*
    To dislay the printed strings by the user (for linked list only)
        -> takes the undo stack and the array having all the strings
        -> extracts all the indexes of the printed strings from the stack
        -> prints the strings at those indexes in order
*/
void print(linkedListStackType list , char str[][10])
{
    int temp[list.count] , i = -1;
    printf("\n\n");
    while(list.top != NULL)
    {
        i++;
        temp[i] = list.top->data;
        list.top = list.top->next;
    }
    for(i = 0 ; i < list.count ; i++)
        printf("\t\t\t%s\n",str[i]);
}


/*
    To implement the undo and redo functionality for linked list stack
        -> 4 options are offered, 
            1-> print the string
                -- to print a random string, user selects any digit from 1 - 6
                -- its index is pushed onto to the stack
                -- strings corresponding to the stack contents are printed
            2-> undo
                -- the index is popped from undo stack
                -- it is pushed onto redo stack
                -- strings corresponding to the stack contents are printed
            3-> redo 
                -- the index is popped from redo stack
                -- it is pushed onto undo stack
                -- strings corresponding to the stack contents are printed
            4-> exit
                -- terminates the function
*/
void llUndoRedo(char str[][10])
{
    char ch1;
    int ch2 , temp;
    linkedListStackType undo = createLLStack();
    linkedListStackType redo = createLLStack();
    while (1)
    {
        system("clear");
        printf("\tEnter you choice:\n");
        printf("\t\t1 -> Print a string\n\t\t2 -> Undo\n\t\t3 -> Redo\n\t\t4 -> exit\n\t");
        scanf(" %c",&ch1);
        switch(ch1)   
        {
            case '1':
                printf("\n\n\tEnter which string you want to print\n\t\t1  ,  2  ,  3  ,  4  ,  5  ,  6\n\n\t");
                scanf("%d",&ch2);
                if(ch2 > 0 && ch2 < 7)
                {
                    pushLL(&undo , ch2);
                    print(undo , str);
                }
                else
                    printf("\n\t\tInvalid choice!!\n");
                sleep(3);
                break;

            case '2':
                if(undo.count > 0)
                {
                    temp = popLL(&undo);
                    pushLL(&redo , temp);
                    print(undo , str);
                }    
                else
                    printf("\tNothing is there to undo\n");
                sleep(3);
                break;
            
            case '3':
                if(redo.count > 0)
                {
                    temp = popLL(&redo);
                    pushLL(&undo , temp);
                    print(undo , str);
                }    
                else
                    printf("\tNothing is there to redo\n");
                sleep(3);
                break;
            
            case '4':
                sleep(2);
                break;
            
            default:
                printf("\n\t\tInvalid choice!!\n");
                sleep(2);
        }
        if(ch1 == '4')
            break;
    }
}

/*
    To implement the undo and redo functionality for array stack
        -> 4 options are offered, 
            1-> print the string
                -- to print a random string, user selects any digit from 1 - 6
                -- its index is pushed onto to the stack
                -- strings corresponding to the stack contents are printed
            2-> undo
                -- the index is popped from undo stack
                -- it is pushed onto redo stack
                -- strings corresponding to the stack contents are printed
            3-> redo 
                -- the index is popped from redo stack
                -- it is pushed onto undo stack
                -- strings corresponding to the stack contents are printed
            4-> exit
                -- terminates the function
*/
void arrUndoRedo(char str[][10])
{
    char ch1;
    int ch2 , temp , j;
    arrayStackType undo = createArrStack(10);
    arrayStackType redo = createArrStack(10);
    while (1)
    {
        system("clear");
        printf("\tEnter you choice:\n");
        printf("\t\t1 -> Print a string\n\t\t2 -> Undo\n\t\t3 -> Redo\n\t\t4 -> exit\n\t");
        scanf(" %c",&ch1);
        switch(ch1)   
        {
            case '1':
                printf("\n\n\tEnter which string you want to print\n\t\t1  ,  2  ,  3  ,  4  ,  5  ,  6\n\n\t");
                scanf("%d",&ch2);
                if(ch2 > 0 && ch2 < 7)
                {
                    pushArr(&undo , ch2);
                    printf("\n");
                    for(j = 0 ; j <= undo.top ; j++)
                        printf("\t\t\t%s\n",str[undo.list[j]]);
                }
                else
                    printf("\n\t\tInvalid choice!!\n");
                sleep(3);
                break;

            case '2':
                if(undo.top >= 0)
                {
                    temp = popArr(&undo);
                    pushArr(&redo , temp);
                    printf("\n");
                    for(j = 0 ; j <= undo.top ; j++)
                        printf("\t\t\t%s\n",str[undo.list[j]]);
                }    
                else
                    printf("\tNothing is there to undo\n");
                sleep(3);
                break;
            
            case '3':
                if(redo.top >= 0)
                {
                    temp = popArr(&redo);
                    pushArr(&undo , temp);
                    printf("\n");
                    for(j = 0 ; j <= undo.top ; j++)
                        printf("\t\t\t%s\n",str[undo.list[j]]);
                }    
                else
                    printf("\tNothing is there to redo\n");
                sleep(3);
                break;
            
            case '4':
                sleep(2);
                break;
            
            default:
                printf("\n\t\tInvalid choice!!\n");
                sleep(2);
        }
        if(ch1 == '4')
            break;
    }
}

/*
    For linked list stack
    -> The function takes an expression from the user
    -> Checks if the parenthesis are correct
        -- A array holds the closing brackets
                '}' , ') , '>' , ']'
        -- The whole expression is traversed, one by one char
        -- If we get any opening bracket,
           the index of its closing bracket is pushed onto the stack
        -- If we get any closing bracket,
           index from the stack is popped and check if the both brackets match
        -- If they don't match, then the expression is wrong
        -- Also, after the whole expression is traversed, the stack must b empty
    -> Output the result, i.e. if correct or wrong
    -> It will repeat the above till '0' is entered to terminate the function
*/
void llParenthesisCheck(char brackets[])
{
    linkedListStackType stack = createLLStack();
    char ch;
    int len , i , flag = 1 , temp;
    do
    {
        system("clear");
        char exp[15];
        flag = 1;
        printf("\n\n\tEnter an expression:\n\t\t");
        scanf("%s",exp);
        len = strlen(exp);
        for(i = 0 ; i < len ; i++)
        {
            if(exp[i] == '{')
            {
                pushLL(&stack , 0);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '(')
            {
                pushLL(&stack , 1);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '<')
            {
                pushLL(&stack , 2);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '[')
            {
                pushLL(&stack , 3);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '}' || exp[i] == ')' || exp[i] == '>' || exp[i] == ']')
            {
                temp = popLL(&stack);
                if(temp < 0)
                    printf("\n\tClosing bracket before any opening bracket\n");
                else
                {
                    if(brackets[temp] != exp[i])
                        printf("\n\tDoesn't match the top opening bracket in the stack\n\t\t%c was expected instead of %c\n",brackets[temp] , exp[i]);
                    else
                    {
                        printf("\t\t%c popped as expected\n",brackets[temp]);
                        continue;
                    }
                }
                flag = 0;
                break;
            }
        }
        if(stack.count > 0)
        {
            flag = 0;
            printf("\n\tThere are still some opening brackets left in the stack\n");
        }
        if(flag == 1)
            printf("\n\n\tThe entered expression is correct\n");
        else
            printf("\n\n\tThe entered expression is wrong\n");

        destroyLLStack(&stack);

        printf("\n\n\tEnter 0 to exit:\t");
        scanf(" %c",&ch);
    }while(ch != '0');        
}

/*
    For array stack
    -> The function takes an expression from the user
    -> Checks if the parenthesis are correct
        -- A array holds the closing brackets
                '}' , ') , '>' , ']'
        -- The whole expression is traversed, one by one char
        -- If we get any opening bracket,
           the index of its closing bracket is pushed onto the stack
        -- If we get any closing bracket,
           index from the stack is popped and check if the both brackets match
        -- If they don't match, then the expression is wrong
        -- Also, after the whole expression is traversed, the stack must b empty
    -> Output the result, i.e. if correct or wrong
    -> It will repeat the above till '0' is entered to terminate the function
*/
void arrParenthesisCheck(char brackets[])
{
    char ch;
    int len , i , flag = 1 , temp;
    do
    {
        system("clear");
        char exp[15];
        flag = 1;
        printf("\n\n\tEnter an expression:\n\t\t");
        scanf("%s",exp);
        len = strlen(exp);
        arrayStackType stack = createArrStack(len);
        for(i = 0 ; i < len ; i++)
        {
            if(exp[i] == '{')
            {
                pushArr(&stack , 0);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '(')
            {
                pushArr(&stack , 1);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '<')
            {
                pushArr(&stack , 2);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '[')
            {
                pushArr(&stack , 3);
                printf("\t\t%c pushed onto the stack\n",exp[i]);
            }
            else if(exp[i] == '}' || exp[i] == ')' || exp[i] == '>' || exp[i] == ']')
            {
                temp = popArr(&stack);
                if(temp >= 9999)
                    printf("\n\tClosing bracket before any opening bracket\n");
                else
                {
                    if(brackets[temp] != exp[i])
                        printf("\n\tDoesn't match the top opening bracket in the stack\n\t\t%c was expected instead of %c\n",brackets[temp] , exp[i]);
                    else
                    {
                        printf("\t\t%c popped as expected\n",brackets[temp]);
                        continue;
                    }
                }
                flag = 0;
                break;
            }
        }
        if(stack.top >= 0)
        {
            flag = 0;
            printf("\n\tThere are still some opening brackets left in the stack\n");
        }
        if(flag == 1)
            printf("\n\n\tThe entered expression is correct\n");
        else
            printf("\n\n\tThe entered expression is wrong\n");

        destroyArrStack(&stack);

        printf("\n\n\tEnter 0 to exit:\t");
        scanf(" %c",&ch);
    }while(ch != '0');        
}

/*
    Two applications are avaible for both types of stacks
        Undo - Redo     and     Parenthesis check
*/
void application(char type)
{
    system("clear");
    char ch , c;
    while (1)
    {
        //terminates when user selectes the exit option
        system("clear");
        printf("\tEnter your choice\n");
        printf("\t\t1 -> Undo - Redo\n\t\t2 -> Parenthesis check\n\t\t3 -> Exit\n\t");
        scanf(" %c",&ch);
        switch (ch)
        {
            case '1':
                system("clear");
                int i;
                char demoStrings[][10] = {"Ghumat " , "Kasale " , "Shamel " , "Dhol " , "Taso " , "Taal "};
                printf("\n\t-> To demonstrate use of stacks for undo-redo,");
                printf("\n\t   let's try printing some words randomly");
                printf("\n\t   from a collection of 6 strings of our choice.\n");
                printf("\n\t-> Try printing, undoing and redoing till you wish to.\n");
                sleep(4);
                printf("\n\n\t-> We will need two stacks for this demo\n");
                printf("\n\t\t   One for undo, where\n\t\t\tall the ids/indexes of printed strings will be pushed,\n\t\t\tonce undone, they will be popped\n");
                printf("\t\t    Then for redo, where\n\t\t\tall the undone ids/indexes will be stored, and\n\t\t\tpopped when redone, and then printed\n");
                sleep(4);
                printf("\n\n\tEnter any key to continue and see the demo: ");
                scanf(" %c",&c);
                if(type == '1')
                    llUndoRedo(demoStrings);
                else
                    arrUndoRedo(demoStrings);
                break;
            
            case '2':
                system("clear");
                char brackets[] = {'}' , ')' , '>' , ']'};
                printf("\n\t-> To demonstrate the use of stacks for parenthesis check,");
                printf("\n\t   enter an expression with the following brackets\n\t\t");
                printf("\n\t   '( )'   '< >'   '{ }'   '[ ]'\n");
                printf("\n\t-> Note that, no check will be done for anything else\n");
                sleep(3);
                printf("\n\t-> The check will done by the following rules:\n");
                printf("\n\t   -- push the opening brackets onto the stack");
                printf("\n\t   -- pop the top element if closing bracket comes");
                printf("\n\t   -- popped element should match the closing bracket");
                printf("\n\t   -- once the expression is checked, stack must be empty");
                printf("\n\t   -- if all the above rules are met, then its correct");
                printf("\n\t   -- otherwise, the parenthesis were wrongly entered\n\n");
                sleep(3);
                printf("\n\n\tEnter any key to continue and see the demo: ");
                scanf(" %c",&c);
                if(type == '1')
                    llParenthesisCheck(brackets);
                else
                    arrParenthesisCheck(brackets);
                break;
            
            case '3':
                sleep(2);
                break;
            
            default:
                printf("\n\t\tInvalid choice!!\n");
                sleep(2);
        }
        if(ch == '3')
            break;
    }   
}