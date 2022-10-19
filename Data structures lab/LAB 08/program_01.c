#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *left;
	struct node *right;
};


char pre[100];
char post[100];

struct node *construct(int pre_low , int pre_high , int post_low , int post_high)
{
	
	struct node *root = (struct node *)malloc(sizeof(struct node));
	//printf("%d %d %d %d\n" , pre_low , pre_high , post_low , post_high);
	int n = pre_high - pre_low + 1;
	
	if (n <= 0) return NULL;
	if (pre_high - pre_low != post_high - post_low) return NULL;
	char r = pre[pre_low];
	
	if(n == 1)
	{
		root->data = r;
		root->left = NULL;
		root->right = NULL;	
		return root;
	}
	else if(n == 2)
	{
		root->data = r;
		
		struct node *r1 = (struct node *)malloc(sizeof(struct node));
		
		r1 -> data = pre[pre_low+1];
		r1->left = NULL;
		r1->right = NULL;
		
		root->left = r1;
		root->right = NULL;	
		
		return root;
		
	}
	
	char lr = pre[pre_low+1];
	char rr = post[post_high-1];
	if(lr == rr)
	{
		
		root->data = r;
		root->left = construct(pre_low+1 , pre_high, post_low , post_high-1);
		root->right = NULL;
		return root;
	}
	int index_1 = -1;
	int index_2 = -1;
	for(int i = pre_low ; i <= pre_high ; i ++)
	{
		if(pre[i] == rr)
		{
			index_1 = i;
			break;
		}
	}
	
	for(int i = post_low ; i <= post_high ; i ++)
	{
		if(post[i] == lr)
		{
			index_2 = i;
			break;
		}
	}
	
	
	root->data = r;
	root->left = construct(pre_low+1 , index_1-1 , post_low , index_2);
	root->right = construct(index_1 , pre_high , index_2+1 , post_high - 1);	
	
	return root;
}

void inorder(struct node *root)
{
	 if(root == NULL) return ;
	 inorder(root->left);
	 printf("%c ",root->data);
	 inorder(root->right);
}

// printing tree

void print(struct node *root)
{
	
}
int main()
{
	
	int n;
	printf("Enter size : ");
	scanf("%d" , &n);
	
	
	
	printf("Enter preorder :");
	scanf("%s" , pre);
	printf("Enter postorder :");
	scanf("%s" , post);
	
	struct node *root = construct(0,n-1 ,0,n-1);
	inorder(root);
	printf("\n\n");
	return 0;
}
