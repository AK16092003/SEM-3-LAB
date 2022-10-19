#include<stdio.h>

int front = 0;
int rear = 0;
int sz = 5;
int queue[5];

void enqueue()
{
	if(front == rear && queue[front] != 0)
	{
		printf("Queue is full !");
	}
	else
	{
		int x;
		printf("Enter element : ");
		scanf("%d" , &x);
		queue[rear] = x;
		rear = (rear+1)%sz;
	}
}

void dequeue()
{
	if(front == rear && queue[front] == 0)
	{
		printf("The queue is empty");
	}
	else
	{
		printf("deleted element : %d " , queue[front]);
		queue[front] = 0;
		front = (front+1)%sz;
	}
	
}

void display()
{
	if(front == rear && queue[front] == 0)
	{
		printf("The queue is empty");
	}
	else
	{
		if(front < rear)
		{
			for(int i = front ; i < rear ; i ++) printf("%d ",queue[i]);
		}
		else
		{
			for(int i = front ; i < sz ; i ++) printf("%d ",queue[i]);
			for(int i = 0 ; i < rear ; i ++) printf("%d ",queue[i]);
			
		}
	}
}

void main()
{
	printf("1) for enqueue\n");
	printf("2) for dequeue\n");
	printf("3) for display\n");
	printf("4) for front , rear elements\n");
	printf("5) is empty\n");
	printf("6) is full\n");

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
		else if(ch == 4)
		{
			if(rear == 0)
			{
				printf("front : %d , rear : %d" , queue[front] , queue[sz-1]);
			}
			else
			{
				printf("front : %d , rear : %d" , queue[front] , queue[rear-1]);
			}
		}
		else if(ch == 5)
		{
			if(front == rear && queue[front] == 0)
			{
				printf("The queue is empty");
			}
			else
			{
				printf("The queue is not empty");
			}
		}
		else if(ch == 6)
		{
			if(front == rear && queue[front] != 0)
			{
				printf("The queue is full");
			}
			else
			{
				printf("The queue is not full");
			}
		}
		printf("\n");	
	}
}
