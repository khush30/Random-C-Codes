#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<time.h>
#include<string.h>
#include <math.h>
#include<unistd.h>

#define SIZE 9
#define RES 5
#define MAX 10

char username[20];
int total_score = 0;

typedef struct
{
	int value;
	char istatic;
}sudoku_type;

typedef struct
{
	int possibilities[SIZE];
	int rpos,cpos;
}solution_type;

typedef struct
{
	char name[20];
	int score;
}user_info_type;

void handler(int signo);

void new_game(int dimension,int *total_score);

int check_solution(sudoku_type **sol, int n);

void find_solution(sudoku_type **sol,int **table,int n);

int backtracking(int **table,int n);

int findBlank(int **table,int *row,int *col,int n);

int check(int rstart,int rend,int cstart,int cend,int **fsol,int n,int x,int row,int col);

int find(int pos,int n);
