#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *head;

void create(int n)
{
	struct node *p , *q;
	p = (struct node *)malloc(sizeof(struct node));
	
	printf("Enter a value 1 : ");
	scanf("%d" , &(p->data));
	p->next = NULL;
	q = p;
	head = p;
	for(int i = 0 ; i < n-1 ; i ++)
	{
		
		p = (struct node *)malloc(sizeof(struct node));
		printf("Enter a value %d : " , (i+2));
		scanf("%d" , &(p->data));
		p->next = NULL;
		q->next = p;
		q = p;
	}
	
}

void display()
{
	struct node *p = head;
	if(p == NULL)
	{
		printf("SinglyLinkedList is empty\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("%d ",p->data);
			p = p->next;
		}
	}
}
int count()
{
	struct node *p = head;
	int c = 0;
	while(p!=NULL)
	{
		p = p->next;
		c+=1;
	}
	return c;
	
}

void search(int x)
{
	int pos = 0;
	int flag = 0;
	struct node *p = head;
	if(p == NULL)
	{
		printf("SinglyLinkedList is empty\n");
	}
	else
	{
		while(p!=NULL)
		{
			if(p->data == x)
			{
				printf("Data found at index : %d\n" , pos);
				flag = 1;
			}
			p = p->next;
			pos++;
		}
	}
	
	if(flag == 0)
	{
		printf("data is not found !");
	}
	
}


void insert_begin()
{
	struct node *p;
	p = (struct node *)malloc(sizeof(struct node));
	printf("Enter a data : ");
	scanf("%d" , &(p->data));
	p->next = head;
	head = p;
}


void insert_middle()
{
	struct node *p , *q;
	p = (struct node *)malloc(sizeof(struct node));
	printf("Enter a data : ");
	scanf("%d" , &(p->data));
	int n;
	printf("Enter index : ");
	scanf("%d" , &n);	

	q = head;	
	for(int i = 1 ; i < n ; i ++)
	{
		q = q->next;
	}
	p->next = q->next;
	q->next = p;
	
}


void insert_end()
{
	struct node *p,*q;
	p = (struct node *)malloc(sizeof(struct node));
	printf("Enter a data : ");
	scanf("%d" , &(p->data));
	p->next = NULL;
	q = head;
	
	while((q->next)!=NULL)
	{
		q = q->next;
	}
	q->next = p;
	
}

void delete_begin()
{
	if(head == NULL)
	{
		printf("SinglyLinkedList is empty\n");
	}
	else
	{
		struct node *deleted_node;
		deleted_node = head;
		printf("deleted data : %d\n" , head->data);
		head = head->next;
		free(deleted_node);
	}
}


void delete_middle()
{
	struct node *q,*r,*s;

	q = head;	
	
	if(q == NULL)
	{
		printf("SinglyLinkedList is empty\n");
	}
	else
	{
		int n;
		printf("Enter index : ");
		scanf("%d" , &n);	
		for(int i = 1 ; i < n ; i ++)
		{
			q = q->next;
		}
		r = q->next;
		s = r->next;
		q->next = s;
		printf("deleted data : %d\n" , r->data);
		free(r);
	}
}


void delete_end()
{
	struct node *p,*q;
	
	q = head;
	if(q == NULL)
	{
		printf("SinglyLinkedList is empty\n");
	}
	else
	{
		while(((q->next)->next)!=NULL)
		{
			q = q->next;
		}
		int data = (q->next)->data;
		struct node *deleted_node;
		
		deleted_node = q->next;
		printf("deleted data : %d\n" , data);
		q->next = NULL;
		
		free(deleted_node);
	}
	
}



int main()
{

	printf("Create a singly linked list \n");
	printf("Enter number of nodes : ");
	int n;
	scanf("%d" , &n);
	
	create(n);
	
	printf("\n1) insert a new node in beginning\n");
	printf("2) insert a new node in middle\n");
	printf("3) insert a new node in end\n");
	printf("4) delete a node in beginning\n");
	printf("5) delete a node in middle\n");
	printf("6) delete a node in end\n");
	printf("7) search for an element in linked list\n");
	printf("8) display all elements in linked list\n");
	printf("9) count of elements in linked list\n\n");
	
	while(1)
	{
		int ch = 0;
		printf("Enter your choice :");
		scanf("%d" , &ch);
		
		if(ch == 1)
		{
			insert_begin();
		}
		else if(ch == 2)
		{
			insert_middle();
		}
		else if(ch ==3)
		{
			insert_end();
		}
		else if(ch == 4)
		{
			delete_begin();
		}
		else if(ch == 5)
		{
			delete_middle();
		}
		else if(ch == 6)
		{
			delete_end();
		}
		else if(ch == 7)
		{
			int x;
			printf("Enter data : ");
			scanf("%d" , &x);
			search(x);
		}
		else if(ch == 8)
		{
			display();
		}
		else if(ch == 9)
		{
			int c = count();
			printf("Count :  %d\n" , c);
		}
		else
		{
			printf("Invalid choice , try again");
		}
		printf("\n\n");
	}
	return 0;
}
