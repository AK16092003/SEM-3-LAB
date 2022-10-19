#include<stdio.h>

int length(char a[])
{
	int len = 0;
	while(a[len] != '\0')
	{
		len++;
	}
	return len;
}


int stack[100];
int top = 0;
void push(int element)
{
	if(top == 100)
	{
		printf("Stack is full\n");
	}
	else
	{
		stack[top] = element;
		top++;
	}
}

int pop()
{
	if(top == 0)
	{
		printf("Stack is empty\n");
	}
	else{
		top -- ;
		return stack[top];
	}
}

void main()
{
	char s[100];
	printf("Enter the expression (seperate with , ): ");
	scanf("%s" , s);
	int n = length(s);
	int cur_num = 0;
	
	for(int i = 0 ; i < n ; i ++ )
	{
		if ('0' <= s[i] && s[i] <= '9')
		{
			cur_num = (cur_num*10) + (s[i] - '0');
		}
		else if(s[i] == ',')
		{
			if(cur_num != 0)
			{
				push(cur_num);
				cur_num = 0;
			}
		}
		else{
			int n2 = pop();
			int n1 = pop();
			
			if(s[i] == '+') push(n1+n2);
			else if(s[i] == '-') push(n1-n2);
			else if(s[i] == '*') push(n1*n2);
			else if(s[i] == '/') push(n1/n2);
		}
		
		if(s[i] == ',' || i == n-1)
		{
			printf("Stack : ");
			for(int i = 0 ; i < top ; i ++ )
			{
				printf("%d " , stack[i]);
			}
			printf("\n");
		}
	}
	printf("\n");
	printf("%d\n" , stack[top-1]);
	
		
}
