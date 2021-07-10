#include"linkedList.h"

void display(list_type start)
{
	node_ptr temp=start;
	printf("\t\t");
	while(temp->next!=NULL)
	{
		printf("%d,\t",temp->data);
		temp=temp->next;
	}
	printf("%d\n",temp->data);
	return;
}

int total_nodes(list_type start)
{
	int count=0;
	node_ptr temp=start;
	while(start!=NULL)
	{
		count++;
		start=start->next;
	}
	return count;
}

list_type add_at_beginning(list_type start,int newValue)
{
	node_type *temp=(node_type*)malloc(sizeof(node_type));
	temp->data=newValue;
	temp->next=start;
	start=temp;
	return start;
}

list_type add_at_end(list_type start,int newValue)
{
	node_ptr ptr,temp=(node_type*)malloc(sizeof(node_type));
	temp->data=newValue;
	temp->next=NULL;
	ptr=start;
	while(ptr->next!=NULL)
		ptr=ptr->next;
	ptr->next=temp;
	return start;
}

list_type positional_insert(list_type start,int newValue,int pos)
{
	int count=1;
	node_ptr cur,temp;
	temp=(node_type*)malloc(sizeof(node_type));
	temp->data=newValue;
	temp->next=NULL;
	cur=start;
	if(pos==1)
	{
		temp->next=start;
		start=temp;
	}
	else
	{
		while(cur->next!=NULL && count<pos-1)
		{
			count++;
			cur=cur->next;
		}
		temp->next=cur->next;
		cur->next=temp;
	}
	return start;
}

list_type insert(list_type start,int newValue)
{
	node_ptr cur,temp,prev;
	temp=(node_type*)malloc(sizeof(node_type));
	temp->data=newValue;
	temp->next=NULL;
	cur=start;
	prev=NULL;
	while(cur!=NULL && cur->data<newValue)
	{
		prev=cur;
		cur=cur->next;
	}
	if(prev==NULL)
	{
		temp->next=cur;
		start=temp;
	}
	else
	{
		temp->next=cur;
		prev->next=temp;
	}
	return start;
}

int search(list_type start,int value)
{
	int pos=0;
	node_ptr temp=start;
	while(temp!=NULL)
	{
		pos++;
		if(temp->data == value)
			break;
		temp=temp->next;
	}
	if(temp==NULL)
		pos=0;
	return pos;
}

list_type modify(list_type start,int pos,int newValue)
{
	int count=1;
	node_ptr temp;
	temp=start;
	while(temp!=NULL && count<pos)
	{
		count++;
		temp=temp->next;
	}
	temp->data=newValue;
	return start;
}

list_type delete_start(list_type start)
{
	node_ptr temp;
	temp=start;
	start=start->next;
	free(temp);
	return start;
}

list_type delete_end(list_type start)
{
	node_ptr cur,prev=NULL;
	cur=start;
	while(cur->next!=NULL)
	{
		prev=cur;
		cur=cur->next;
	}
	free(cur);
	if(prev==NULL)
		start=NULL;
	else
		prev->next=NULL;
	return start;
}

list_type delete_element(list_type start,int pos)
{
	int count=2;
	node_ptr temp,ptr;
	ptr=start;
	if(pos==1)
	{
		start=start->next;
		free(ptr);
	}
	else
	{
		while(count<pos)
		{
			ptr=ptr->next;
			count++;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
	}
	return start;
}

list_type reverse(list_type start)
{
	node_ptr prev,cur;
	prev=start;
	cur=start->next;
	start->next=NULL;
	while(cur!=NULL)
	{
		prev=cur;
		cur=cur->next;
		prev->next=start;
		start=prev;
	}
	return start;
}

list_type destroy(list_type start)
{
	node_ptr temp;
	while(start!=NULL)
	{
		temp=start;
		start=start->next;
		free(temp);
	}
	return NULL;
}
