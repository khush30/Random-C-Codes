#include"bstfunctions.h"

void main()
{
	char choice,cont;
	int newdata;
	short int flag;
	bstType tree;
	tree.root=NULL;
	tree.count=0;
	tree.height=-1;
	do
	{
		system("clear");
		printf("\tEnter your choice\n\t\t1-> Insert\n\t\t2-> Display inorder\n\t\t3-> Display preorder\n\t\t4-> Display postorder\n\t\t5-> Search\n\t\t6-> Delete an element\n\t\t7-> Find count and height\n\t\t8-> Exit\n\t");
		scanf(" %c",&choice);
		switch(choice)
		{
			case '1':																//insertion in sorted manner(ascending)
				printf("\n\tEnter the value to be inserted:\t");
				scanf("%d",&newdata);
				insertnode(&tree,newdata);
				break;
			case '2':																//inorder
				if(tree.count)
					inorder(tree.root);
				else
					printf("\tEmpty tree!\n");
				break;
			case '3':																//preorder
				if(tree.count)
					preorder(tree.root);
				else
					printf("\tEmpty tree!\n");
				break;
			case '4':																//postorder
				if(tree.count)
					postorder(tree.root);
				else
					printf("\tEmpty tree!\n");
				break;
			case '5':																//search for given value
				if(tree.count)
				{
					int value,level;
					printf("\n\tEnter the value to be searched:\t");
					scanf("%d",&value);
					flag=search(tree.root,value,&level);
					if(flag)
						printf("\n\t%d present at level %d\n",value,level);
					else
						printf("\n\t%d not present in the tree\n");
				}else
					printf("\tEmpty tree!\n");
				break;
			case '6':
				if(tree.count)
				{
					printf("\n\tEnter the value to be deleted:\t");
					scanf("%d",&newdata);
					flag=deletenode(&tree,newdata);
					if(flag)
					{
						tree.count--;
						printf("\n\t%d deleted successfully from the tree\n",newdata);
						tree.height=findheight(tree.root);
					}
					else
						printf("\n\t%d not present in the tree\n");
				}else
					printf("\tEmpty tree!\n");
				break;
			case '7':															//display count of nodes and height of the tree
				printf("\n\tCount = %d\t\tHeight = %d\n",tree.count,tree.height);
				break;
			case '8':				
				system("clear");
				break;
			default:
				printf("\n\n\t\tInvalid choice!");
		}
		if(choice!='8')
		{
			printf("\n\tEnter any character to continue:\t");
			scanf(" %c",&cont);
		}
	}while(choice!='8');
}
