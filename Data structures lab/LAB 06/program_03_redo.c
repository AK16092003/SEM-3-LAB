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
	struct node *p , *q , *r;
	p = head;
	q = p->next;
	p->next = NULL;
	for(int i = 0 ; i < n ; i ++)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;
	}
	//s->next = r;
	return head;
}



void display(struct node *head , int n)
{
	struct node *p = head;
	//while(p!=NULL)
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
		display(head , n);
		
		printf("\n");
			
	}
}
