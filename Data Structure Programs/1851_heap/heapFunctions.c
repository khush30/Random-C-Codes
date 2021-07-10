#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void display(int *nodes,int maximum)
{
	int n=0,i,m=1,j,k;
	while(pow(2,n)<=maximum)
		n++;
	n--;
	printf("\n");
	for(i=0;i<150;i++)
		printf("-");
	printf("\n\n\tGraphical representation:\n\n");
	for(i=0;i<150;i++)
		printf("-");
	printf("\n\n");			
	for(i=n;i>=0 && m<=maximum;i--)
	{
		for(j=1;j<pow(2,i) && m<maximum;j++)
			printf("\t");
		for(j=0;j<pow(2,n-i)-1 && m<maximum;j++)
		{
			printf("%d",nodes[m-1]);
			m++;
			for(k=1;k<pow(2,i+1);k++)
				printf("\t");
			printf("\t");
		}
		printf("%d\n\n",nodes[m-1]);
		m++;
	}
	for(i=0;i<150;i++)
		printf("-");
	printf("\n\n");
}

void swap(int *num1,int *num2)
{
	int temp;
	temp=*num1;
	*num1=*num2;
	*num2=temp;
}

void reheapup(int *nodes,int i)
{
	int parent;
	short int flag=1;
	while(i>=0 && flag)
	{
		parent=(i-1)/2;
		if(nodes[i] > nodes[parent])
		{
			swap(&nodes[i],&nodes[parent]);
			i=parent;
		}
		else
			flag=0;
	}
}

void reheapdown(int *nodes, int start, int size)
{
	int left,right,max;
	while(start<size)
	{
		left=2*start+1;
		right=2*start+2;
		if(left<size)
		{
			if(right<size)
			{
				if(nodes[left]<nodes[right])
					max=right;
				else
					max=left;
			}
			else
				max=left;
			if(nodes[max]>nodes[start])
				swap(&nodes[start],&nodes[max]);
			start=max;
		}
		else
			break;
	}
}

void heapSort(int *nodes,int n)
{
	short int i,j,k,left,right,max;
	for(i=n-1;i>0;i--)
	{
		swap(&nodes[i],&nodes[0]);
		reheapdown(nodes,0,i);
	}
}

void replace(int *nodes,int size,int position,int value)
{
	int parent;
	nodes[position]=value;
	if(position)
	{
		parent=(position-1)/2;
		if(nodes[position]>nodes[parent])
			reheapup(nodes,position);
		else
			reheapdown(nodes,position,size);
	}
	else
		reheapdown(nodes,position,size);
}

void deleteElement(int *nodes,int value,int *n)
{
	short int flag=0,i;
	int size=*n,left,right,max;
	for(i=0;i < size && !flag;i++)
		if(nodes[i]==value)
			flag=1;
	if(flag)
	{
		if(i != size)
		{
			swap(&nodes[i-1],&nodes[size - 1]);
			i--;
			reheapdown(nodes,i,size-1);
		}
		*n-=1;
	}
}

void deleteRoot(int *nodes,int *n)
{
	int size=*n;
	if(size>1)
	{
		swap(&nodes[0],&nodes[size-1]);
		reheapdown(nodes,0,size-1);
	}
	*n-=1;
}

void heapcreate(int *nodes,int n)
{
	int i=0,j,leftmost,parent;
	while(i<n)
	{
		i=2*i+1;
	}
	leftmost=(i-1)/2;
	while(parent > 0)
	{
		parent=(leftmost-1)/2;
		while(parent<leftmost)
		{
			reheapdown(nodes,parent,n);
			parent++;	
		}
		leftmost=(leftmost-1)/2;
	}
}
