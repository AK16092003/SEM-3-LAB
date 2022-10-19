#include<stdio.h>

int stack[100];
int top = 0;

void push(int element)
{
	if(top == 100)
	{
		printf("Stack size is full\n");
	}
	else
	{
		stack[top] = element;
		top++;
	}
}

void pop()
{
	if(top == 0)
	{
		printf("Stack is empty\n");
	}
	else{
		top -- ;
		printf("popped element : %d\n", stack[top] );
		stack[top] = -1;
	}
}

void main()
{
	printf("Operations : \n");
	printf("1. push to stack\n");
	printf("2. pop from stack\n");
	while(1)
	{
		int choice;
		printf("Enter your choice : ");
		scanf("%d" , &choice);
		
		if(choice == 1)
		{
			int x;
			printf("Enter element : ");
			scanf("%d" , &x);
			push(x);
			printf("top = %d \n" , top);
		}
		else if(choice == 2)
		{
			pop();
			printf("top = %d \n" , top);
		}
		else
		{
			printf("Invalid choice !\n");
		}
		printf("\n");
	}
		
}
