#include"projectio.h"

void main()
{
	if(signal(SIGINT,handler)==SIG_ERR)
			printf("\n\n\t\tJaina\n");
	int dimension,i,j,k,flag=1,**table,count,quit;
	char c,user[MAX],choice;
	FILE *fp;
		srand(time(0));
		count=0;
		system("clear");
		intro();
		while(1)
	  	{	
	  		count=0;
	  		char name_res;
	  		fp=fopen("test.txt","r");
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
				printf("\n\n\t\t\t\t\tThis name already exist, score: %d\n\t\t\t\t\t💡HINT: Enter some character to try something new.. Or type 'c' to continue with the same username\n\t",total_score);
				scanf(" %c",&name_res);
				if(name_res=='C' || name_res=='c')
				{
					printf("\n\n\t\t\t\t\tAll the best for the game!\n");
					break;
				}
			}
			fclose(fp);
		}
		count=0;
		total_score=0;
		printf("\n\n\t\t\t\t\tEnter any character to continue:\n\n\t\t\t\t\t");
		scanf(" %c",&c);
		system("clear");
		
		menu();
			
		
}
