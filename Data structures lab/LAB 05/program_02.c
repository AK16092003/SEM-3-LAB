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

struct node *rotate(struct node *head , int k)
{
	
	int sz = 1;
	struct node *p = head , *q = head;
	while(p->next!=NULL)
	{
		p = p->next;
		sz++;
	}
	p->next = head;
	for(int i = 0 ; i < sz-k-1 ; i++)
	{
		q = q->next;
	}
	head = q->next;
	q->next = NULL;
	return head;

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

int main()
{

	printf("Create a linked list : \n");
	int n;
	printf("Enter size : ");
	scanf("%d" , &n);
	struct node *head = create(n);
	
	while(1){
	
		printf("Enter k: (number of places of right rotation) :");
		int k;
		scanf("%d" , &k);
		k = k%n;
		head = rotate(head , k);
		printf("\nLinked list after rotation: \n");
		display(head);
		printf("\n");
	}
		
	return 0;
}

