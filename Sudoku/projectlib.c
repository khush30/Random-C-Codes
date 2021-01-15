#include"projectio.h"


void handler(int signo)
{
	char ch;
	if(signo==SIGINT)
	{
		printf("\n\t\t\t\tYour score won't be recorded\n\n\n\t\t\t\tEnter any character to go to the main menu!\t");
		scanf(" %c",&ch);
		menu();
	}
	if(signo==SIGTSTP)
	{
		int i,j,n=0;
		system("clear");
		user_info_type scores[20],temp;
		FILE *in=fopen("test.txt","r");
		while(!feof(in))
		{
			fscanf(in,"%s%d",scores[n].name,&scores[n].score);
			n++;
		}
		fclose(in);
		for(i=1;i<n;i++)
		{
			for(j=1;j<=n-i;j++)
				if(scores[j].score > scores[j-1].score)
				{
					temp=scores[j];
					scores[j]=scores[j-1];
					scores[j-1]=temp;
				}
		}
		for(i=0;i<n && i<5;i++)
			printf("\n\t\t\t\t%s\t\t:\t%d",scores[i].name,scores[i].score);
			
		printf("\n\t\t\t\t\tEnter a character to continue...\t");
		scanf(" %c",&ch);
	}
}

void new_game(int dimension,int *total_score)
{
	FILE *new;
	short int err,line,i,j;
	int **table;
	sudoku_type **problem_table;
	char buffer[dimension*2*dimension+2];
	table=(int**)malloc(dimension*sizeof(int *));
	for(i=0;i<dimension;i++)
		table[i]=(int*)malloc(dimension*sizeof(int));
	problem_table=(sudoku_type**)malloc(dimension*sizeof(sudoku_type *));
	for(i=0;i<dimension;i++)
		problem_table[i]=(sudoku_type*)malloc(dimension*sizeof(sudoku_type));
	if(dimension==4)
		new=fopen("easy","r");
	else
		new=fopen("hard","r");
	if(new==NULL)
		err=1;
	else
		err=0;
	if(err)
		printf("\tDue to some technical issues, the new game feature is not working.. please try again later\n");
	else
	{
		line=rand()%5;
		fgets(buffer,sizeof(buffer)-1,new);
		while(line)
		{
			fgets(buffer,sizeof(buffer)-1,new);
			line--;
		}
		err=0;
		for(i=0;i<dimension;i++)
		{
			for(j=0;j<dimension;j++)
			{
				problem_table[i][j].value=buffer[err]-48;
				problem_table[i][j].istatic=buffer[err+1];
				if(buffer[err+1]=='.')
					table[i][j]=buffer[err]-48;
				else
					table[i][j]=0;
				err+=2;
			}
		}
		accept_solution(problem_table,dimension);
		system("clear");
		if(check_solution(problem_table,dimension))
		{
			*total_score+=dimension*5;
			printf("\tCongratulations!!! You Won!!\n\t\tPoints scored: %d\n\t\tTotal score: %d",dimension*5,*total_score);
		}
		else
			printf("\tOoops... You need to practice more... Try again later\n\t\tTotal score: %d",*total_score);
	}
}

int check_solution(sudoku_type **sol, int n)//return 1 if solution is correct, 0 otherwise
{
	short int i,j,sum,rsum,csum,flag=1,rstart,cstart;
	sum=n*(n+1)/2;
	for(i=0;i<n && flag;i++)//to check if the sum of all the rows, columns and each block is same or not
	{
		rsum=0;
		csum=0;
		for(j=0;j<n;j++)
		{
			rsum+=sol[i][j].value;
			csum+=sol[j][i].value;
		}
		if(rsum!=sum || csum!=sum)
			flag=0;
	}
	return flag;
}


void find_solution(sudoku_type **sol,int **table,int n)//to compute all the possible values that can go on the solution values
{
	int i,j,k=0,flag=n*n,chk,rstart,cstart,a,temp;
	solution_type pos[flag];
	for(i=0;i<n;i++)//to determine the problem set and number of blank/solution places
		for(j=0;j<n;j++)
			if(sol[i][j].istatic=='.')
			{
				table[i][j]=sol[i][j].value;
				flag--;
			}
			else
			{
				pos[k].rpos=i;
				pos[k].cpos=j;
				k++;
			}	
	display(sol,n,table,n,n);
	while(flag)//to put all possible surely going values in the blanlk places
	{
		temp=flag;
		for(i=0;i<k && !table[pos[i].rpos][pos[i].cpos];i++)
		{
			a=1;
			for(j=1;j<=n;j++)
			{
				chk=check(pos[i].rpos,pos[i].rpos+1,0,n,table,n,j,n,n);
				if(chk)
					chk=check(0,n,pos[i].cpos,pos[i].cpos+1,table,n,j,n,n);
				if(chk)
				{
					chk=sqrt(n);
					rstart=find(pos[i].rpos,chk);
					cstart=find(pos[i].cpos,chk);
					chk=check(rstart,rstart+chk,cstart,cstart+chk,table,n,j,n,n);
				}
				if(chk)
					pos[i].possibilities[a++]=j;
			}
			if(a==1)
			{
				printf("\n\tThe sudoku problem do not have any solution..\n");
				i=k;
				flag=0;
			}
			else
			{
				pos[i].possibilities[0]=a-1;
				if(pos[i].possibilities[0]==1)
				{
					table[pos[i].rpos][pos[i].cpos]=pos[i].possibilities[1];
					flag--;
				}
			}
		}
		if(flag==temp)
		{
			system("clear");
			char c;
			printf("\tThese are all the possible values that can go on the blank places:\n");
			for(i=0;i<k;i++)//to display all the possibilities 
			{
				printf("\n\tRow: %d and Column: %d\n\t\t",pos[i].rpos+1,pos[i].cpos+1);
				for(j=1;j<=pos[i].possibilities[0];j++)
					printf("%d ",pos[i].possibilities[j]);
			}
			printf("\n\n\tEnter any character to see the solution:\t");
			scanf(" %c",&c);
			system("clear");
			if(backtracking(table,n))//to compute the solution using backtracking
			{
				printf("\n\tThe soution is: \n");
				display(sol,n,table,n,n);
			}
			else
				printf("\n\tThe solution do not exists!\n");
			break;
		}
	}
	return;
}

int backtracking(int **table,int n)
{
	int row,col,i,flag,chk;
	if(!findBlank(table,&row,&col,n))
		return 1;
	for(i=1;i<=n;i++)
	{
		chk=check(row,row+1,0,n,table,n,i,n,n);
		if(chk)
		{
			chk=check(0,n,col,col+1,table,n,i,n,n);
			if(chk)
			{
				chk=sqrt(n);
				int rstart=find(row,chk);
				int cstart=find(col,chk);
				chk=check(rstart,rstart+chk,cstart,cstart+chk,table,n,i,n,n);
				if(chk)
				{
					table[row][col]=i;
					if(backtracking(table,n))
						return 1;
					table[row][col]=0;
				}
			}
		}
	}
	return 0;
}

int findBlank(int **table,int *row,int *col,int n)//to find the next blank location in the table
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			if(table[i][j]==0)
			{
				*row=i;
				*col=j;
				return 1;
			}
	return 0;
}

int check(int rstart,int rend,int cstart,int cend,int **fsol,int n,int x,int row,int col)//to check if a number is present in the given locality
{
	int i,j,flag=1;
	for(i=rstart;i<rend && flag;i++)
		for(j=cstart;j<cend && flag;j++)
		{
			if(i==row && j==col)
				continue;
			if(x==fsol[i][j])
				flag=0;
		}
	return flag;
}

int find(int pos,int n)//to find the starting positions of the blocks in the sudoku table
{
	int i;
	i=pos%n;
	if(i)
		pos-=i;
	return pos;
}



/*

*****************
* 1 | 2 * 3 | 4 *
*-------*-------*
* 1 | 2 * 3 | 4 *
*****************
* 1 | 2 * 3 | 4 *
*-------*-------*
* 1 | 2 * 3 | 4 *
*****************
*/
