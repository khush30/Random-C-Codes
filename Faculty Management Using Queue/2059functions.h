#include<stdio.h>

//maximum number of faculty members defined here
#define MAX 50
#define YEAR 2021

//structure for a certificate node
typedef struct node{
	char title[50];
	char dateOfCompletion[11];
	struct node *next;
}certificationNode;

//structure to hold all the certificates
//using queue implementation using linked list because
//		-> the insertion and display frequency is the same, and the no of insertions can vary. So linked list os preferred over stack
//		-> while displaying, the recent ones will go at the bottom, which implies that it can be first-in first-out approach. so queue is used 
typedef struct{
	int count;
	certificationNode *first;
	certificationNode *last;
}certificatesList;

//structure for faculty member
//to hold the list of all the faculty members, array is chosen as:
//		-> insertion/deletion will happen rarely, so the list will be more or less of finite size
//		-> search operations are frequent, so using array implementation, search can be made efficient
typedef struct{
	int UID;
	char firstName[20];
	char lastName[20];
	char designation[30];
	char dateOfJoining[11];
	certificatesList certificates;
}facultyMember;

typedef struct{
	int count;
	facultyMember member[MAX];
}facultyList;

//to clear the screen
void enter_to_continue(FILE *in);
//to input a valid date in standard format
void takeDate(char *date);
//insert faculty member in the list
facultyList insertFaculty(facultyList faculty, char first[20], char last[20], char date[11], char designation[30]);
//searches faculty by last name
int searchByLastName(facultyList faculty, char last[20]);
//displays details of each member
void displayDetails(facultyMember node);
//displays all certificates
void displayCertificates(certificatesList certificates);
//searches by UID of the faculty
int searchByUid(facultyList faculty, int uid);
//inserts certificate
certificatesList insertCertificate(certificatesList certificates , char title[50], char date[11]);
