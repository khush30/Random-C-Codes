#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>
#include<string.h>
#include<time.h>
#define max 15
#define limit 10

typedef struct
{
	char name[20];
	int score;
}user_info_type;

char username[max];
int total_score;
short int flag=0,alm;
char answer;

void handler(int);
void menu();
void scoreBoard();
void new_game();
void display(int,int);
short int check_solution(int);

void handler(int signo)
{
	char ch;
	if(signo==SIGINT)
	{
		printf("\n\t\t\t\tYour option:\t");
		scanf(" %c",&answer);
		flag=1;
	}
	if(signo==SIGTSTP)
	{
		printf("\n\t\t\t\tYour score won't be recorded\n\n\n\t\t\t\tEnter any character to go to the main menu!\t");
		scanf(" %c",&ch);
		menu();
	}
	if(signo==SIGALRM)
	{
		alm++;
		if(alm>limit)
			alm=0;
		else
			alarm(1); 
	}
}

void display(int line,int file)
{
	system("clear");
	short int i;
	char command[30];
	printf("\n\t\t\t\t   Date:%s\t\t  NEW QUIZ \t\tTime:%s\n",__DATE__,__TIME__);
	printf("\t\t\t\t________________________________________________________________________\n\n\n");
	if(file<5)
		for(i=line;i<line+5;i++)
		{
			sprintf(command,"sed -n %dp easy.txt",i);
			system(command);
			printf("\n");
		}
	else
		for(i=line;i<line+5;i++)
		{
			sprintf(command,"sed -n %dp difficult.txt",i);
			system(command);
			printf("\n");
		}
}

short int check_solution(int line)
{
	short int res=0;
	FILE *fp=fopen("answers.txt","r");
	char temp;
	fseek(fp,line*2,SEEK_SET);
	temp=fgetc(fp);
	if(answer==temp)
		res=1;
	fclose(fp);
	return res;
}

void scoreBoard()
{
	FILE *out;
	char name[max];
	int points;
	out=fopen("info.txt","r");
	printf("\n\n\t\t\t\t   Date:%s\t\t  SCORE BOARD \t\tTime:%s\n",__DATE__,__TIME__);
	printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
	while(!feof(out))
	{
		fscanf(out,"%s%d",name,&points);
		printf("\n\n\t\t\t\t\t\t%s\t:\t%d\n",name,points);
	}
	fclose(out);
}

void new_game()
{
	srand(time(0));
	signal(SIGINT,handler);
	signal(SIGTSTP,handler);
	FILE *esy,*diff;
	short int err=0,line,i,j,count=10,quest,easy=0,points;
	char ch,buffer[100],option[4][50];
	while(count)
	{
		printf("\n\n\t\t\t\tEnter a character to see question no: %d\t\t",10-count+1);
		scanf(" %c",&ch);
		flag=0;
		srand(time(0));
		line=rand()%25;
		quest=line*5+1;
		display(quest,easy);
		printf("\n\t\t\t\tEnter your option in 10 seconds!\n\t\t\t\t\tPress 'ctrl+c' to give the answer!\n");
		alm=1;
		alarm(1);
		signal(SIGALRM,handler);
		while(alm && !flag);
		if(flag)
		{
			if(easy<5)
				points=2;
			else
				points=4;
			system("clear");
			if(check_solution(line))
			{
				if(alm)
				{
				total_score+=points;
				printf("\t\t\t\t\t\t\tCorrect answer!!\n\t\t\t\tPoints scored: %d\n\t\t\t\tTotal score: %d",points,total_score);
				easy++;
				}
				else
				{
					total_score-=points/2;
					printf("\t\t\t\t\tOoops... You missed the deadline! Points deducted\n\t\t\t\t\t\tTotal score: %d",total_score);
				}
			}
			else
			{
				total_score-=points/2;
				printf("\t\t\t\t\tOoops... Wrong answer... Points deducted\n\t\t\t\t\t\tTotal score: %d",total_score);
			}
		}
		count--;
	}
	user_info_type temp,temp2;
	strcpy(temp2.name,username);
	temp2.score=total_score;
	FILE *tmp=tmpfile();
	int c=0,n;
	i=0;
	FILE *fp=fopen("info.txt","r");
	while(!feof(fp))
	{
		fscanf(fp,"%s%d",temp.name,&temp.score);
		i++;
	}
	n=i;
	rewind(fp);
	while(n)
	{
		fscanf(fp,"%s%d",temp.name,&temp.score);
		if(!strcmp(username,temp.name))
		{
			if(total_score < temp.score)
				temp2.score=temp.score;
		}
		else
		{
			fwrite(&temp,sizeof(temp),1,tmp);
			c++;
		}
		n--;
	}
	fwrite(&temp2,sizeof(temp),1,tmp);
	c++;
	fclose(fp);
	fp=fopen("info.txt","w");
	rewind(tmp);
	while(c)
	{
		fread(&temp,sizeof(temp),1,tmp);
		fprintf(fp,"%s\t%d",temp.name,temp.score);
		c--;
	}
	fclose(fp);
	fclose(tmp);
}

void menu()
{	
		int i,count;
		short int flag;
		FILE *fp;
		char choice,ch;
		do
		{
			system("clear");
			printf("\n\t\t\t\t************************************************************************\n");
			printf("\n\t\t\t\t  Welcome, %s\n\n\t\t\t\t\t\t\t\t SMART QUIZ \n",username);
			printf("\n\n\t\t\t\t   Date:%s\t\t   MENU \t\tTime:%s\n",__DATE__,__TIME__);
			printf("\t\t\t\t________________________________________________________________________\n\n");
			printf("\t\t\t\t________________________________________________________________________\n\n");
			printf("\n\t\t\t\t\tEnter your choice\n\t\t\t\t\t1-> Start a quiz\n\t\t\t\t\t2-> View all the scores\n\t\t\t\t\t3-> Exit\n\n");
			printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
			scanf(" %c",&choice);
			switch(choice)
			{
				case '1':
					system("clear");
					srand(time(0));
					total_score=0;
					new_game();
					break;
				case '2':
					system("clear");
					scoreBoard();
					break;
				case '3':
					system("clear");
					printf("\n\n\t\t\t\t\t\t\tThank you for playing!\n\n\t\t\t\t\t\tProgram will be terminated in some time!\n\n");
					break;
				default:
					printf("\n\n\t\t\t\tInvalid input!!\n");
			}
			if(choice!='3')
			{
				printf("\n\n\t\t\t\tEnter a character to continue:\t");
				scanf(" %c",&ch);
			}
		}while(choice!='3');
		sleep(2);
		system("clear");
		exit(0);
}

void main()
{
	int dimension,i,j,k,flag=1,count;
	char c,user[max],choice;
	system("clear");
	printf("\n\n\t\t\t\t   Date:%s\t\t  SMART QUIZ \t\tTime:%s\n",__DATE__,__TIME__);
	printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
	FILE *fp;
	while(1)
  	{	
  		count=0;
  		char name_res;
  		fp=fopen("info.txt","r");
  		if(fp==NULL)
  		{
  			printf("\n\tSorry, the score file seems to be missing... Please try again later\n");
  			exit(-1);
  		}
		printf("\n\t\t\t\t\tEnter a user name:");
		scanf("%s",&username);
		while(!feof(fp))
		{		
			fscanf(fp, "%s %d",user,&total_score); /*read from file*/
			if(!strcmp(username,user))
			{
				count=1;
				break;
			}
		}
		if(!count)
			break;
		else
		{
			printf("\n\n\t\t\tThis name already exist, score: %d\n\t\t\t\t\tHINT: Enter some character to try something new.. Or type 'c' to continue with the same username\n\t",total_score);
			scanf(" %c",&name_res);
			if(name_res=='C' || name_res=='c')
			{
				printf("\n\n\t\t\t\t\tAll the best for the game!\n");
				break;
			}
		}
		fclose(fp);
	}
	printf("\n\n\t\t\t\t\tEnter any character to continue:\n\n\t\t\t\t\t");
	scanf(" %c",&c);
	system("clear");
	menu();
}
