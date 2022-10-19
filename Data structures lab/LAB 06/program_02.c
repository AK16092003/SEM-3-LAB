#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct node *create(int n)
{
	struct node *p , *q , *head;
	struct node *array[n];
	
	for(int i = 0 ; i < n ; i ++)
	{
		array[i] = (struct node *)malloc(sizeof(struct node));
	}
	for(int i = 0 ; i < n ; i ++)
	{
		if(i == 0)
		{
			printf("HEAD NODE:\n");
		}
		printf("Enter data : ");
		scanf("%d",&(array[i]->data));
		printf("Enter next pointer (-1 for NULL) :");
		int k;
		scanf("%d" , &k);
		if(k == -1)
		{
			array[i]->next = NULL;
		}
		else if(k<n)
		{
			array[i]->next = array[k];
		}
		else
		{
			printf("Invalid pointing to node !");
			array[i]->next = NULL;
		}
	}
	
	
	head = array[0];
	return head;

}


void display(struct node *head , int n)
{
	struct node *p = head;
	for(int i = 0 ; i < n ; i ++)
	{
		printf("%d " , p->data);
		p = p->next;
	}
}

int check_circular(struct node *head)
{
	struct node *p , *q;
	
	int flag = 1;
	
	p = head;
	q = head;
	
	p = p->next;
	q = q->next->next;
	
	while(p!=q)
	{
		p = p->next;
		q = q->next;
		if(q == NULL)
		{
			flag = 0;
			break;
		}
		q = q->next;
		if(q == NULL)
		{
			flag = 0;
			break;
		}
	}
	
	return flag;
}

void main()
{
	while(1)
	{
		printf("Enter number of nodes : ");
		int n;
		scanf("%d" , &n);
		struct node *head  = create(n);
		
		printf("\nlinked list : ");
		display(head , n);
		
		int flag = check_circular(head);
		printf("\n");
		
		if(flag == 1)
		{
			printf("Yes it is a circular linked list \n");
		}
		else
		{
			printf("No , it is not a circular linked list\n");
		}
		printf("\n");
			
	}
}
