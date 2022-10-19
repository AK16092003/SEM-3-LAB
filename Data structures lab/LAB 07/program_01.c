#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};


struct node *head = NULL;


void insert(int data)
{
	// create a node 
	struct node *p , *q;
	p = (struct node *) malloc(sizeof(struct node));
	p->data = data;
	p->left = NULL;
	p->right = NULL;
	
	if(head == NULL)
	{
		// initial state 
		head = p;
	}
	else
	{
		q = head;
		
		while(1)
		{
			if(data <= q->data)
			{
				// go to left
				if(q->left == NULL)
				{
					q->left = p;
					break;
				}
				else
					q = q->left;
			}
			else
			{
				// go to right
				if(q->right == NULL)
				{
					q->right = p;
					break;
				}
				else
					q = q->right;
			}
		}
	}

}


void search(int element)
{
	struct node *q = head;
	
	int found = 0;
	while(q!=NULL)
	{
		if(element == q->data)
		{
			found = 1;
			break;
		}
		else if(element < q->data)
		{
			q = q->left;
		}
		else
		{
			q = q->right;
		}
	}
	
	if(found == 1)
	{
		printf("Search data is found!");
	}
	else
	{
		printf("Search data is not found !");
	}
}


void inorder(struct node *root)
{
	// left root right
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d " , root->data);
		inorder(root->right);		
	}
}



void preorder(struct node *root)
{
	// root left right
	if(root != NULL)
	{
		printf("%d " , root->data);
		preorder(root->left);
		preorder(root->right);		
	}
}


void main()
{
	printf("Create a Binary Search Tree\n");
	int n;
	printf("Enter number of elements : ");
	scanf("%d" , &n);
	
	for(int i = 0 ; i < n ; i ++)
	{
		int element = 0;
		printf("Enter data : ");
		scanf("%d" , &element);
		insert(element);
	}
	
	printf("\n\n");
	printf("1) Search a element \n");
	printf("2) Inorder Traversal \n");
	printf("3) Preorder Traversal\n");
	printf("4) Exit\n");
	
	while(1)
	{
	
		
		int ch = 0;
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		
		if(ch == 1)
		{
			int el = 0;
			printf("Enter search element : ");
			scanf("%d" , &el);
			search(el);
		}
		else if(ch==2)
		{
			inorder(head);
		}
		else if(ch == 3)
		{
			preorder(head);
		}
		else
		{
			printf("\n\nThank you !\n");
			break;
		}
		printf("\n\n");
		
	}
}
