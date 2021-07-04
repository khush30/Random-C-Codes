#include"2059functions.h"
#include<stdlib.h>
#include<string.h>


void enter_to_continue(FILE *in)
{	
	//flush
	int ch;
	do
		ch = fgetc ( in ); 
	while ( ch != EOF && ch != '\n' ); 
	clearerr ( in );
	
	//pause
	printf ( "Press [Enter] to continue: " );
	fflush ( stdout );
	getchar();

	system("clear");
}

//for simplicity:
//		-> have not considered a leap year, february will have 28 days
//		-> year check is done till 2021 (till december accepted)
void takeDate(char *date){
	
	int m, d, y;
	
	printf("\t\t\tMonth(1-12):\t");
	do{
		scanf("%d", &m);
		if(m > 0 && m < 13)
			break;
		printf("\n\tEnter valid month (1-12):\t");
	}while(1);
	
	do{
		printf("\t\t\tDay");
		int flag = 1;
		switch(m){
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				printf("(1-31):\t");
				do{
					scanf("%d", &d);
					if(d > 0 && d < 32)
						break;
					printf("\n\tEnter valid day (1-31):\t");
				}while(1);
				break;
			
			case 4:
			case 6:
			case 9:
			case 11:
				printf("(1-30):\t");
				do{
					scanf("%d", &d);
					if(d > 0 && d < 31)
						break;
					printf("\n\tEnter valid day (1-30):\t");
				}while(1);
				break;
				
			case 2:
				printf("(1-28):\t");
				do{
					scanf("%d", &d);
					if(d > 0 && d < 29)
						break;
					printf("\n\tEnter valid day (1-28):\t");
				}while(1);
				break;
				
			default:
				flag = 0;
		}
		if(flag)
			break;
		printf("\n\tEnter valid day please:\n\n");
	}while(1);
	
	printf("\t\t\tYear(1990 - %d):\t", YEAR);
	do{
		scanf("%d", &y);
		if(y > 1989 && y <= YEAR)
			break;
		printf("\n\tEnter valid year (1990 - %d):\t", YEAR);
	}while(1);
	
	sprintf(date, "%d" , d);
	char month[2];
	sprintf(month, "%d" , m);
	strcat(date, "-");
	strcat(date, month);
	strcat(date, "-");
	char year[4];
	sprintf(year, "%d" , y);
	strcat(date, year);
}

//inserts faculty member
facultyList insertFaculty(facultyList faculty, char first[20], char last[20], char date[11], char designation[30]){
	static int start = 10000;
	if(faculty.count < MAX){
		faculty.member[faculty.count].UID = start + faculty.count;
		strcpy(faculty.member[faculty.count].firstName, first);
		strcpy(faculty.member[faculty.count].lastName, last);
		strcpy(faculty.member[faculty.count].designation, designation);
		strcpy(faculty.member[faculty.count].dateOfJoining, date);
		faculty.count++;
		faculty.member[faculty.count].certificates.count = 0;
		faculty.member[faculty.count].certificates.first = NULL;
		faculty.member[faculty.count].certificates.last = NULL;
	}
	else
		printf("\n\n\tInsertion failed due to max limit\n");
		
	return faculty;
}

//display certificates
void displayCertificates(certificatesList certificates){
	certificationNode *ptr = certificates.first;
	int i = 1;
	while(ptr != NULL){
		printf("\t\t%d\t-> Certificate Title\t: %s\n", i, ptr->title);
		printf("\t\t\tDate of Completion\t: %s\n\n", ptr->dateOfCompletion);
		ptr = ptr->next;
		i++;
	}
}

//displays member details
void displayDetails(facultyMember node){
	
	printf("\n\n\tUID\t\t\t: %d\n\tName\t\t\t: %s %s\n\tDesignation\t\t: %s\n\tDate of Joining\t\t: %s\n", node.UID, node.firstName, node.lastName, node.designation, node.dateOfJoining);
	printf("\n\tCertification Details:\n");
	
	if(node.certificates.count > 0)
		displayCertificates(node.certificates);
	else
		printf("\t\tNo certificates to be displayed yet\n");
	printf("-----------------------------------------------------------------------------------\n");
	
}

//searches by last name of the faculty
int searchByLastName(facultyList faculty, char last[20]){
	int flag = 0;
	if(faculty.count > 0){
		int i;
		for(i = 0 ; i < faculty.count ; i++){
			if(strcmp(last , faculty.member[i].lastName))
				continue;
			displayDetails(faculty.member[i]);
			flag = 1;
		}
	}
	else
		printf("\n\tNo records in the list yet\n");
	return flag;
}

//searches by UID of the faculty
int searchByUid(facultyList faculty, int uid){
	for(int i = 0 ; i < faculty.count ; i++){
		if(faculty.member[i].UID == uid)
			return i;
	}
	return -1;
}

//inserts certificate
certificatesList insertCertificate(certificatesList certificates , char title[50], char date[11]){
	certificationNode *certificate = (certificationNode*)malloc(sizeof(certificationNode));
	strcpy(certificate->title, title);
	strcpy(certificate->dateOfCompletion, date);
	certificate->next = NULL;
	
	if(certificates.count == 0){
		certificates.first = certificate;
		certificates.last = certificate;
	}
	else{
		certificates.last->next = certificate;
		certificates.last = certificate;
	}
	certificates.count += 1;
	
	return certificates;
}
