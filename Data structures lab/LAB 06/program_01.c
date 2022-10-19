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
	p = (struct node *)malloc(sizeof(struct node));
	printf("Enter data : ");
	scanf("%d",&(p->data));
	p->next = NULL;
	head = p;
	for(int i = 0 ; i < n-1 ; i ++)
	{
			
		q = (struct node *)malloc(sizeof(struct node));
		printf("Enter data : ");
		scanf("%d",&(q->data));
		q->next = NULL;
		p->next = q;
		p = q;
	}
	return head;

}

struct node *reverse( struct node *head)
{
	struct node *p , *q , *r;
	q = (struct node *) malloc(sizeof(struct node));
	q->data = head->data;
	head = head->next;
	q->next = NULL;
	r = q;
	while(head != NULL)
	{
		p = (struct node *) malloc(sizeof(struct node));
		p->data = head->data;
		head = head -> next;
		p->next = q;
		q = p;
		r = p;
	}
	
	return r;
}



void display(struct node *head)
{
	struct node *p = head;
	while(p!=NULL)
	{
		printf("%d " , p->data);
		p = p->next;
	}
}


void main()
{
	while(1)
	{
		printf("Enter size : ");
		int n;
		scanf("%d" , &n);
		struct node *head  = create(n);
		struct node *rev = reverse(head);
		
		printf("\nreverse linkedlist : ");
		display(rev);
		
		int flag = 0;
		while(rev!=NULL && head!=NULL)
		{
			if(rev->data != head->data)
			{
				flag = 1;
				break;
			}
			rev = rev->next;
			head = head->next;
		}
		printf("\n");
		if(flag == 0)
		{
			printf("Yes it is a palindrome \n");
		}
		else
		{
			printf("No , it is not a palindrome \n");
		}
		printf("\n");
			
	}
}
