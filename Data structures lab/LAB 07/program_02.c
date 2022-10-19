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

int tree_size(struct node *root)
{
	if(root == NULL) return 0;
	return 1 + tree_size(root->left) + tree_size(root->right);
}

int isempty()
{
	int n = tree_size(head);
	if(n == 0) return 1;
	return 0;
}

int width(struct node *root , int n)
{
	if(root == NULL) return 0;
	if(n == 0) return 1;
	
	return width(root->left , n-1) + width(root->right , n-1);
}


void main()
{
	
	printf("\n\n");
	printf("1) Insert a element \n");
	printf("2) Is empty \n");
	printf("3) Size\n");
	printf("4) Width\n");
	printf("5) Exit\n");
	
	while(1)
	{
	
		
		int ch = 0;
		printf("Enter your choice : ");
		scanf("%d" , &ch);
		
		if(ch == 1)
		{
			int element = 0;
			printf("Enter data : ");
			scanf("%d" , &element);
			insert(element);
		}
		else if(ch==2)
		{
			if (isempty())
			{
				printf("Binary Search Tree is Empty !");
			}
			else
			{
				printf("Binary Search Tree is not Empty !");
			}
		}
		else if(ch == 3)
		{
			int n = tree_size(head);
			printf("Size of binary tree = %d\n" , n);
		}
		else if(ch == 4)
		{
			int n;
			printf("Enter level : ");
			scanf("%d" ,  &n);
			
			int w = width(head , n);
			printf("Number of nodes in level %d = %d\n\n" , n , w);
		
		}
		else
		{
			printf("\n\nThank you !\n");
			break;
		}
		printf("\n\n");
		
	}
}
