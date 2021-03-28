#include"functionLib.h"
#include<unistd.h>

void main()
{
    char carryon;
    do
    {
        char choice1 , choice2;
        while(1)
        {
            /*
                this infinite while loop will be exited only if
                    -> correct choices are selected
                    -> exit option is selected
            */
            system("clear");
            printf("\tEnter you choice:\n\t\t1 -> Stack using linked list\n\t\t2 -> Stack using array\n\t\t3 -> Exit\n\t");
            //choice1 - to select between array and linked list
            scanf(" %c",&choice1);
            if(choice1 == '1' || choice1 == '2')
            {
                system("clear");
                printf("\tEnter you choice:\n\t\t1 -> Check the implementations of the stack\n\t\t2 -> Check the applications of the stack\n\t");
                //choice2 - to select between implementation or application demo
                scanf(" %c",&choice2);
                if(choice2 == '1' || choice2 == '2')
                    break;
                //else it will print the error msg below and take the inputs again
             }
            else if(choice1 == '3')
            {
                printf("\n\n\tOk, bye bye...\n");
                exit(0);
            }
            printf("\tYou entered invalid input!");
        }

        if(choice1 == '1' && choice2 == '1')
        {
            /*
                where some basics functions of stack 
                using linked list can be be tested
            */
           implementationLL();
        }
        else if(choice1 == '2' && choice2 == '1')
        {
            /*
                where some basics functions of stack 
                using array can be be tested
            */
           implementationArr();
        }
        else
        {
            /*
                where some applications of stack 
                using linked list / array can be be tested
                depending on the user's choice
            */
           application(choice1);
        }

        printf("\tEnter 'y' to continue\n\tEnter any other key to exit\n");
        scanf(" %c",&carryon);
        
    } while (carryon == 'y' || carryon == 'Y');
    //the above do..while loop will terminate is y is not entered, and program will end
    system("clear");
}