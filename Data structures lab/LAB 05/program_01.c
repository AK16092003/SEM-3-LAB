#include<stdio.h>
#include<stdlib.h>

/*

       brute force -> inefficient way
        
	array
	
	a[0] -> O -> O -> O -> null
	a[1] -> O -> O -> null
	a[2] -> O -> O -> O -> O -> null
	a[3] -> O -> O -> O -> null

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

struct node *combine(struct node *array[] , int k)
{
	int no = k;
	
	struct node *head , *q;
	head = (struct node *)malloc(sizeof(struct node));
	head->next = NULL;
	q = head;
	while(1)
	{
		struct node *p;
		p = (struct node *)malloc(sizeof(struct node));
		p->next = NULL;
		
		int min = -1;
		for(int i = 0 ; i < k ; i ++)
		{
			if(array[i]!=NULL)
			{
				if(min == -1)
				{
					min = array[i]->data;
				}
				else
				{
					if(min > (array[i]->data))
					{
						min = array[i]->data;
					}
				}
			}
		}
		
		if(min == -1) break;
		
		p->data = min;
		
		for(int i = 0 ; i < k ; i ++)
		{
			if(array[i]!=NULL && array[i]->data == min)
			{
				array[i] = array[i]->next;
				break;
			}
		}
		q->next = p;
		q = p;
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
	
	struct node *main_head = combine(array , k); 
	
	printf("\nCombined Linked list :\n");
	display(main_head);
	printf("\n\n");
	return 0;
}

