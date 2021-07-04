#include"2059functions.h"
#include<stdlib.h>

void main(){
	
	facultyList faculty;
	faculty.count = 0;
	
	char ch;
	
	do{
		system("clear");
		printf("\n\n\tEnter your choice\n\t\t1 -> Insert Faculty\n\t\t2 -> Insert Certificate\n\t\t3 -> Search-&-Display\n\t\t4 -> Display All\n\t\t5 -> Exit\n\t");
		scanf(" %c", &ch);
		
		switch(ch){
			case '1':
				system("clear");
				{
					char first[20], last[20], date[11], designation[30];
					printf("\n\n\tEnter the following details\n");
					printf("\t\tFirst Name:\t");
					scanf("%s", first);
					printf("\t\tLast Name:\t");
					scanf("%s", last);
					printf("\t\tDesignation:\t");
					scanf("%s", designation);
					printf("\t\tDate of joining:\n");
					takeDate(date);
					
					faculty = insertFaculty(faculty, first, last, date, designation);
				}
				break;
			case '2':
				system("clear");
				{
					if(faculty.count > 0){
						char title[50], date[11];
						int pos;
						int uid;
						printf("\n\n\tEnter the following details:\n");
						printf("\t\tUID\t: ");
						scanf("%d", &uid);
						pos = searchByUid(faculty, uid);
						if(pos > -1){
							printf("\n\n\t\tCertificate Title\t: ");
							scanf("%s", title);
							printf("\t\tDate of Completion:\n");
							takeDate(date);
							faculty.member[pos].certificates = insertCertificate(faculty.member[pos].certificates , title, date);
						}
						else
							printf("\n\t\tDoesn't exist\n");
					}
					else
						printf("\n\n\tNo members in the list yet\n");
				}
				break;
			case '3':
				system("clear");
				{
					char last[20];
					printf("\n\n\tEnter the last name:\t");
					scanf("%s", last);
					
					if(!searchByLastName(faculty, last))
						printf("\n\t\tDoesn't exist\n");
				}
				break;
			case '4':
				system("clear");
				{
					if(faculty.count > 0){
						for(int i = 0 ; i < faculty.count ; i++)
							displayDetails(faculty.member[i]);
					}
					else
						printf("\n\n\tNo members in the list yet\n");
				}
				break;
			case '5':
				system("clear");
				printf("\n\nTerminating the program....\n\n\n");
				break;
			default:
				printf("\n\n\t\tInvalid Input!! Please select a valid number from the given menu...\n\n");
		}
		
		enter_to_continue(stdin);
				
	}while(ch != '5');
}
