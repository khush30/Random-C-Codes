#include"projectlib.h"


void intro();
int dimensions();
void scoreBoard();
void accept_problem(sudoku_type **sol,int dimension);
int validate_input(sudoku_type **sol,int dimension,int **temp);
void accept_solution(sudoku_type **sol,int n);
void display(sudoku_type **sol,int n,int **temp,int row,int col);
void menu();
