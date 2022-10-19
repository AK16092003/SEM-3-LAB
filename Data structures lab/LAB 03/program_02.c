#include<stdio.h>


// using 2 stacks


int sp1 = 0;
int sp2 = 0;


int sz = 5;
int stack1[5];
int stack2[5];

void stack1_push(int x)
{
	if(sp1 >= sz)
	{
	    printf("Overflow stack 1\n");
	    return ;
	}
	stack1[sp1] = x;
	sp1++;
}

void stack2_push(int x)
{
	if(sp2 >= sz)
	{
	    printf("Overflow stack 2\n");
	    return ;
	}
	stack2[sp2] = x;
	sp2++;
}
int stack1_pop()
{
	if(sp1 == 0)
	{
	    printf("Underflow stack 1\n");
	    return 0;
	}
	sp1--;
	return stack1[sp1];
}
int stack2_pop()
{
	if(sp2 == 0)
	{
	    printf("Underflow stack 2\n");
	    return 0;
	}
	sp2--;
	return stack2[sp2];
}

void enqueue()
{
 
	int x;
	printf("Enter element : ");
	scanf("%d" , &x);
	// push to stack 1 - primary stack
	stack1_push(x);
}

void dequeue()
{
	// pop all elements from stack 1 to stack 2
	while(sp1 > 0)
	{
		int element = stack1_pop();
		stack2_push(element);
	}
	int d = stack2_pop();
	printf("Deleted element : %d\n" , d);
	
	while(sp2 > 0)
	{
		int element = stack2_pop();
		stack1_push(element);	
	}
	
}

void display()
{
	for(int i = 0 ; i < sp1 ; i ++)
	{
	 	printf("%d " , stack1[i]);
	}
	printf("\n");
}

void main()
{
	printf("Queue using 2 stacks \n");
	printf("1) for enqueue\n");
	printf("2) for dequeue\n");
	printf("3) for display\n");

	while(1)
	{
		printf("Enter your choice : ");
		int ch;
		scanf("%d" , &ch);
		if(ch == 1)
		{
			enqueue();
			
		}
		else if(ch==2)
		{
			dequeue();
		}
		else if(ch == 3)
		{
			display();
		}
		printf("\n");	
	}
}
