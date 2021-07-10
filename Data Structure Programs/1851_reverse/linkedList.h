#include<stdio.h>
#include<stdlib.h>
#define new() system("clear")

typedef struct node
{
	int data;
	struct node *next;
}node_type;

typedef node_type* list_type;
typedef node_type* node_ptr;

void display(list_type list);
int total_nodes(list_type start);
list_type add_at_beginning(list_type list,int value);
list_type add_at_end(list_type start,int newValue);
list_type positional_insert(list_type start,int newValue,int pos);
list_type insert(list_type start,int newValue);
int search(list_type start,int value);
list_type modify(list_type start,int pos,int newValue);
list_type delete_start(list_type start);
list_type delete_end(list_type start);
list_type delete_element(list_type start,int pos);
list_type destroy(list_type start);
list_type reverse(list_type start);
