#include<stdio.h>
#include<stdlib.h>


/*

	combine many linked lists , 2 at a time
	> optimal
	o
       /\
      o  o
     /\  /\
     o o o o

*/

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



void display(struct node *head)
{
	struct node *p = head;
	while(p!=NULL)
	{
		printf("%d " , p->data);
		p = p->next;
	}
}

struct node *combine(struct node *head1 , struct node *head2)
{
	
	struct node *r , *s;
	
	struct node *head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	s = head;
	
	while(head1 != NULL || head2 !=NULL)
	{
		int min = 0;
		if(head1 == NULL) 
		{
			s->next = head2;
			break;
		}  
		else if(head2 == NULL)
		{
			s->next = head1;
			break;
		}
		else
		{
			if(head1->data < head2->data)
			{
				r = head1;
				head1 = head1->next;
				s->next = r;
				r->next = NULL;
			}
			else
			{
				r = head2;
				head2 = head2->next;
				s->next = r;
				r->next = NULL;
			}
		}
		s = r;
	}
	return head->next;
}

int main()
{
	printf("Enter total number of linked list : ");
	int k = 0;
	scanf("%d" , &k);
	struct node *array[k];
	for(int i = 0 ; i < k ; i ++)
	{
		printf("Create linked list %d: \n" , (i+1));
		int n;
		printf("Enter size : ");
		scanf("%d" , &n);
		struct node *head = create(n);
		array[i] = head;
	}
	printf("\n\n");
	for(int i = 0 ; i < k ; i ++)
	{
		printf("Linkedlist %d : " , (i+1));
		display(array[i]);
		printf("\n");
	}
	printf("\n");
	
	int sz = k , i = 0;
	while(sz!=1)
	{	
		if(sz%2 == 0)
		{
			for(i = 0 ; i < sz/2 ; i ++)
			{
				array[i] = combine(array[2*i] , array[2*i+1]); 
				printf("Combine %d , %d : " ,2*i+1 , 2*i+2);
				display(array[i]);
				printf("\n");
			}
			sz = sz/2;
		}
		else
		{
			for(i = 0 ; i < sz/2 ; i ++)
			{
				array[i] = combine(array[2*i] , array[2*i+1]); 
				printf("Combine %d , %d : " ,2*i+1 , 2*i+2);
				display(array[i]);
				printf("\n");
			}
			array[i] = array[2*i]; 
			sz = (sz+1)/2;
		
		}
		printf("\n");
	}
	
	printf("\nCombined Linked list :\n");
	display(array[0]);
	printf("\n\n");
	return 0;
}

