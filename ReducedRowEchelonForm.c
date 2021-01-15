#include<stdio.h>

void exchangeRows(int c , float matrix[][c] , int i , int k);

void exchangeRows(int c , float matrix[][c] , int i , int k)
{
	int t;
	float temp;
	for(t = 0  ; t < c ; t++)
	{
		temp = matrix[i][t];
		matrix[i][t] = matrix[k][t];
		matrix[k][t] = temp;
	}
}

void displayRREF(int r , int c , float matrix[][c]);

void displayRREF(int r , int c , float matrix[][c])
{
	int i , j ;
	printf("\t\t");
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
			printf("%f\t" , matrix[i][j]);
		printf("\n\t\t");
	}
	printf("\n");
}

void main()
{
	int r , c , i , j;
	printf("\tEnter the dimensions of the matrix:\n\t\tRow\t: ");
	scanf("%d" , &r);
	printf("\t\tColumn\t: ");
	scanf("%d" , &c);
	
	float matrix[r][c];
	
	printf("\tEnter the matrix to be changed in Row Reduced Echelon Form:\n\t\t");
	for(i = 0 ; i < r ; i++)
	{
		for(j = 0 ; j < c ; j++)
			scanf("%f" , &matrix[i][j]);
		printf("\t\t");
	}
	
	int flag = 0;
	
	for(i = 0 ; i < r ; i++)
		for(j = 0 ; j < c ; j++)
			if(matrix[i][j] != 0)
			{
				flag = 1;
				break;
			}
			
	if(flag)
	{
		int k , l;
		float a , mul;
		for(i = 0 ; i < r ; i++)
		{
			printf("\n\tRow: %d\n" , i+1);
			a = 0;
			for(j = i ; j < c && !a ; j++)
			{
				for(k = i ; k < r && !a ; k++)
				{
					if(matrix[k][j] != 0)
						if(k > i)
						{
							a = matrix[k][j];
							printf("\n\t%d and %d rows exchanged\n" , i+1 , k+1);
							exchangeRows(c , matrix , i , k);
							displayRREF(r , c , matrix);
						}
						else
						{
							a = matrix[k][j];
						}
				}
			}
			if(a != 0)
			{
				j--;
				for(k = 0 ; k < c ; k++)
				{
					if(matrix[i][k] == 0)
						continue;
					matrix[i][k] *= (1/a);			
				}
				printf("\t%d row\n" , i+1);
				displayRREF(r , c , matrix);
				for(k = 0 ; k < r ; k++)
				{
					if(k == i)
						continue;
					if(matrix[k][j] == 0)
						continue;
					mul = matrix[k][j];
					for(l = 0 ; l < c ; l++)
					{
						matrix[k][l] -= (matrix[i][l] * mul);
					}
				}
				printf("\tsome columns changed\n");
				displayRREF(r , c , matrix);
			}
		}
	}
			
	displayRREF(r , c , matrix);
	
}
