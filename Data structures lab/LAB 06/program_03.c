#include<stdio.h>
#include<stdlib.h>


struct node
{
	int data;
	struct node *next;
};

struct node *create(int n)
{
	// circular linked list
	
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
	
	p->next = head;
	
	return head;

}

struct node *reverse( struct node *head , int n)
{
	struct node *p , *q , *r , *s;
	
	q = (struct node *) malloc(sizeof(struct node));
	q->data = head->data;
	head = head->next;
	q->next = NULL;
	
	r = q;
	s = r;
	
	for(int i = 0 ; i < n-1 ; i ++)
	{
	
		p = (struct node *) malloc(sizeof(struct node));
		p->data = head->data;
		head = head -> next;
		p->next = q;
	
		q = p;
		r = p;
	}
	s->next = r;
	return r;
}



void display(struct node *head , int n)
{
	struct node *p = head;

	for(int i = 0 ; i < n ; i++)
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
		struct node *rev = reverse(head , n);
		
		printf("\nreverse linkedlist : ");
		display(rev , n);
		
		printf("\n");
			
	}
}
