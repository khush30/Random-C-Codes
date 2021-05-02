#include"projectlib.h"


#define print(x) for(short int i=0;i<150;i++)printf("%s",#x);
#define RED "\x1b[31m"
#define BLOCK "\x1b[46m"
#define YELLOW "\x1b[33m"
#define RESET "\x1b[0m"



void intro()
{
		printf("\n\n\n\t\t\t\t   Date:%s\t\t  SUDOKU \t\tTime:%s\n",__DATE__,__TIME__);
		printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
	
}

int dimensions()//returns the dimension
{
	int flag=0;
	char choice;
	do
	{
		printf("\n\t\t\t\t\t\tEnter your choice\n\t\t\t\t\t\t1-> Easy\n\t\t\t\t\t\t2-> Hard\n");
		printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t\t");
		scanf(" %c",&choice);
		if(choice=='1')
			flag=4;
		else if(choice=='2')
			flag=9;
		else
			printf("\n\n\t\t\t\tInvalid Choice\n");
	}while(!flag);
	return flag;
}

void display(sudoku_type **table,int n,int **temp,int row,int col)//to display the sudoku problem
{
	short int i,j,p=sqrt(n),t=n*4+1,c;
	printf("\n");
	printf("\n\t\t\t\t   Date:%s\t\t  SUDOKU \t\tTime:%s\n",__DATE__,__TIME__);
	printf("\t\t\t\t________________________________________________________________________\n\t\t\t\t\t");

	for(i=0;i<n;i++)
	{
		printf("\n\t\t\t\t\t");
		if(i%p==0)
			for(c=0;c<t-1;c++)
				printf(RED "*" RESET);
		else
			for(c=0;c<n;c++)
			{
				if(c%p==0)
					printf(RED "*" RESET);
				else
					printf("-");
				printf("---");
			}
		printf(RED "*" RESET);
		printf("\n\t\t\t\t\t");
		for(j=0;j<n;j++)
		{
			if(j%p==0)
				printf(RED "*" RESET);
			else
				printf("|");
			if(table[i][j].istatic=='.')
				printf(BLOCK " %d " RESET,table[i][j].value);
			else
				if(i==row && j==col)
					printf(YELLOW" %d " RESET,temp[i][j]);
				else
					printf(" %d ",temp[i][j]);
		}
		printf(RED "*" RESET);
	}
	printf("\n\t\t\t\t\t");
	for(c=0;c<t;c++)
		printf(RED "*" RESET);
	printf("\n\t");
}

int validate_input(sudoku_type **sol,int dimension,int **temp)
{
	int i,j,flag=1,rstart,cstart;
	for(i=0;i<dimension && flag;i++)
		for(j=0;j<dimension && flag;j++)
			if(sol[i][j].value>dimension)
			{
				printf("\n\tValues entered are wrong\n\tMistake found at row: %d and column: %d, number: %d\n\tValues can be from 1 to %d\n\tPlease re-enter\n\n",i+1,j+1,sol[i][j].value,dimension);
				flag=0;
			}
	if(flag)
	{
		for(i=0;i<dimension && flag;i++)
			for(j=0;j<dimension && flag;j++)
				if(temp[i][j])
				{
					flag=check(i,i+1,0,dimension,temp,dimension,temp[i][j],i,j);
					if(flag)
					{
						flag=check(0,dimension,j,j+1,temp,dimension,temp[i][j],i,j);
						if(flag)
						{
							flag=sqrt(dimension);
							rstart=find(i,flag);
							cstart=find(j,flag);
							flag=check(rstart,rstart+flag,cstart,cstart+flag,temp,dimension,temp[i][j],i,j);
							if(!flag)
								printf("\n\t\t%d at row: %d and column: %d repeated in it's block\n",temp[i][j],i+1,j+1);
						}
						else
							printf("\n\t\t%d repeated in the column: %d\n",temp[i][j],j+1);
					}
					else
						printf("\n\t\t%d repeated in the row: %d\n",temp[i][j],i+1);
				}
		if(!flag)
		{
			display(sol,dimension,temp,dimension,dimension);
			printf("\n\tQuestion set seems wrong\n\tPlease re-enter carefully\n\n\t");
		}
	}
	return flag;
}

void accept_solution(sudoku_type **sol,int n)//lets the user give in solution to the displayed sudoku problem set
{
	int i,j,count=1,**temp,t,flag,row,col,c_flag=0;
	char res,choice;
	temp=(int **)malloc(n*sizeof(int *));
	for(i=0;i<n;i++)
		temp[i]=(int *)malloc(n*sizeof(int));
	for(i=0;i<n;i++)//to determine the problem set
		for(j=0;j<n;j++)
			if(sol[i][j].istatic=='.')
				temp[i][j]=sol[i][j].value;
			else
				temp[i][j]=0;
	display(sol,n,temp,n,n);
	if(!findBlank(temp,&i,&j,n))
		printf("\n\n\t\t\t\t\tThere are no blank places to be filled... Please follow the intructions properly while inputing\n");
	else
	{
		do
		{	
			do
			{
				system("clear");
				display(sol,n,temp,i,j);
				printf("\n\t\t\t\t\tYou are at\n\t\t\t\t\tROW: %d\t\tCOLUMN: %d\n\t\t\t\t\tEnter your choice:\n\t\t\t\t\t'q' -> To enter\n\t\t\t\t\t'w' -> To search upwards\n\t\t\t\t\t's' -> To search downwards\n\t\t\t\t\t'a' -> To search to the left side\n\t\t\t\t\t'd' -> To search to the right\n",i+1,j+1);
				printf("\t\t\t\t\t'ctrl+c' to quit the game and go to the main menu");
				if(c_flag==1)
					printf("\n\t\t\t\t\t'z' -> To proceed\n");								
				printf("\n\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
				scanf(" %c",&choice);
				switch(choice)
				{
					case 'a':
						flag=0;
						for(t=j-1;t>=0 && !flag;t--)
							if(sol[i][t].istatic != '.')
								flag=1;
						if(flag)
							j=t+1;
						else
							printf("\n\t\t\t\t\tNo values can be changed on the left side!\n");
						break;
					case 'd':
						flag=0;
						for(t=j+1;t<n && !flag;t++)
							if(sol[i][t].istatic != '.')
								flag=1;
						if(flag)
							j=t-1;
						else
							printf("\n\t\t\t\t\tNo values can be changed on the right side!\n");
						break;
					case 'w':
						flag=0;
						for(t=i-1;t>=0 && !flag;t--)
							if(sol[t][j].istatic != '.')
								flag=1;
						if(flag)
							i=t+1;
						else
							printf("\n\t\t\t\t\tNo values can be changed on the left side!\n");
						break;
					case 's':
						flag=0;
						for(t=i+1;t<n && !flag;t++)
							if(sol[t][j].istatic != '.')
								flag=1;
						if(flag)
							i=t-1;
						else
							printf("\n\t\t\t\t\tNo values can be changed on the left side!\n");
						break;
					case 'z':	c_flag=1;
								break;	
					case 'q': 	while(1)
								{
									printf("\t\t\t\t\tEnter the value: ");
									scanf("%d",&temp[i][j]);
									if(temp[i][j]>n)
										printf("\n\n\t\t\t\t\tYou can enter numbers from 1 to %d only!\n",n);
									else
										break;
								}
								break;		
					default:
						printf("\n\n\t\t\t\t\tInvalid input!");
				}
			}while((choice!='q') && (c_flag!=1));
			
			if(!findBlank(temp,&row,&col,n))
			{
				system("clear");
				display(sol,n,temp,n,n);			
				printf("\n\n\t\t\t\t\tAre you done entering?🐈\n\n\t\t\t\t\tEnter 'y' to proceed\n\n\t\t\t\t\tEnter any other character to make changes\n\n\t\t\t\t\t");
				scanf(" %c",&res);
				if(res=='y' || res=='Y')
					count=0;
				else
				{
					count=1;	
					c_flag=1;
				}	
			}
		}while(count);
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if(sol[i][j].istatic!='.')
					sol[i][j].value=temp[i][j];
	}
}

void accept_problem(sudoku_type **sol,int dimension)
{
	int i,j,**temp,flag;
	temp=(int**)malloc(dimension*sizeof(int *));
	for(i=0;i<dimension;i++)
		temp[i]=(int*)malloc(dimension*sizeof(int));
	printf("\n\n\t\t\t\tEnter the solution to be checked\n\n\t\t\t\t NOTE: Enter the problem set first.. Enter 0's where your solution will go\n\n\t\t\t\t");
	do
	{
		for(i=0;i<dimension;i++)
		{
			for(j=0;j<dimension;j++)
			{
				scanf("%d",&sol[i][j].value);
				if(sol[i][j].value > 0)
					sol[i][j].istatic='.';
				else
					sol[i][j].istatic=',';
				temp[i][j]=sol[i][j].value;
			}
			printf("\t");
		}
		flag=validate_input(sol,dimension,temp);
	}while(!flag);
	system("clear");
	printf("\n\n\t\t\t\tNow enter your solution to be checked:\n");
	accept_solution(sol,dimension);
	return;
}

void scoreBoard()
{
	FILE *out;
	char name[MAX];
	int points;
	out=fopen("test.txt","r");
	printf("\n\n\t\t\t\t   Date:%s\t\t  SUDOKU \t\tTime:%s\n",__DATE__,__TIME__);
	printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
	while(!feof(out))
	{
		fscanf(out,"%s%d",name,&points);
		printf("\n\n\t\t\t\t\t%s\t:\t%d\n",name,points);
	}
	fclose(out);
	signal(SIGTSTP,handler);
	printf("\n\n\t\tEnter 'ctrl+z' to see the top 5 scores!");
}

void menu()
{	
		int dimension,i,count,**table;
		short int flag;
		FILE *fp;
		sudoku_type **problem_table;
		char choice,ch;
		do//to exit or continue with the same user name
		{
			system("clear");
			printf("\n\t\t\t\t************************************************************************\n");
			printf("\n\t\t\t\t  Welcome, %s\n\n\t\t\t\t\t\t\t\t SUDOKU \n",username);
			printf("\n\n\t\t\t\t   Date:%s\t\t   MENU \t\tTime:%s\n",__DATE__,__TIME__);
			printf("\t\t\t\t________________________________________________________________________\n\n");
			printf("\n\t\t\t\t\tEnter the difficulty level\n\n\t\t\t\t\tNote that\n\t\t\t\t\tEasy -> 4*4\n\t\t\t\t\tDifficult -> 9*9\n\n\t\t\t");
			dimension=dimensions();//to accept the dimensions
			problem_table=(sudoku_type**)malloc(dimension*sizeof(sudoku_type *));
			for(i=0;i<dimension;i++)
				problem_table[i]=(sudoku_type*)malloc(dimension*sizeof(sudoku_type));
			system("clear");

			printf("\n\n\n\t\t\t\t   Date:%s\t\t   MENU \t\tTime:%s\n",__DATE__,__TIME__);
			printf("\t\t\t\t________________________________________________________________________\n\n");
			printf("\n\t\t\t\t\tEnter your choice\n\t\t\t\t\t1-> New game\n\t\t\t\t\t2-> Check solution\n\t\t\t\t\t3-> View all the scores\n\t\t\t\t\t4-> Exit\n\n");
			printf("\t\t\t\t________________________________________________________________________\n\n\t\t\t\t\t");
			scanf(" %c",&choice);
			switch(choice)
			{
				case '1':
					system("clear");
					srand(time(0));
					new_game(dimension,&total_score);//gives a new sudoku problem set to the user
					break;
				case '2':
					system("clear");
					count = 0;
					problem_table=(sudoku_type**)malloc(dimension*sizeof(sudoku_type *));
					for(i=0;i<dimension;i++)
						problem_table[i]=(sudoku_type*)malloc(dimension*sizeof(sudoku_type));
					accept_problem(problem_table,dimension);//accepts the solution to be checked
					do//to give the user 2 more chances to give correct solution
					{
						flag=check_solution(problem_table,dimension);//checks if the solution is correct or not
						if(flag)
							printf("\n\n\t\t\t\tYour solution is correct\n");
						else
						{
							printf("\n\n\t\t\t\tYour solution is not correct\n");
							count++;
							if(count==3)
								printf("\n\n\t\t\t\tYou need to try harder... Keep trying... Good luck!\n\n\t\t\t\tFor now, let us help you to get the solution\n\n");
							else
							{
								printf("\n\n\t\t\t\tNumber of chance available: %d\n\n\t\t\t\tDo not give up\n\n\t\t\t\tEnter 'n' to quit and see the solution: \n\n\t\t\t\t",3-count);
								scanf(" %c",&ch);
								if(ch=='n' || ch=='N')
								{
									flag=0;
									count=3;
									break;
								}
								system("clear");
								accept_solution(problem_table,dimension);
							}
							
						}	
					}while(count<3 && !flag);
					if(!flag)
					{
						table=(int**)malloc(dimension*sizeof(int *));
						for(i=0;i<dimension;i++)
							table[i]=(int*)malloc(dimension*sizeof(int));
						find_solution(problem_table,table,dimension);
					}
					break;
				case '3':
					system("clear");
					scoreBoard();
					break;
				case '4':
					system("clear");
					user_info_type temp,temp2;
					strcpy(temp2.name,username);
					temp2.score=total_score;
					FILE *tmp=tmpfile();
					int c=0,i=0,n;
					fp=fopen("test.txt","r");
					while(!feof(fp))
					{
						fscanf(fp,"%s%d",temp.name,&temp.score);
						i++;
					}
					n=i-1;
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
					fp=fopen("test.txt","w");
					rewind(tmp);
					while(c)
					{
						fread(&temp,sizeof(temp),1,tmp);
						fprintf(fp,"%s\t%d",temp.name,temp.score);
						c--;
					}
					fclose(fp);
					fclose(tmp);
					printf("\n\n\tThank you for playing!\n\n\tProgram will be terminated in some time!\n\n\t\tEnter 'ctrl+z' to see the score board\n\n");
					signal(SIGTSTP,handler);
					break;
				default:
					printf("\n\n\t\t\t\tInvalid input!!\n");
			}
			if(choice!='4')
			{
				printf("\n\n\t\t\t\tEnter a character to continue:\t");
				scanf(" %c",&ch);
			}
		}while(choice!='4');
		sleep(3);
		system("clear");
		exit(0);
}


