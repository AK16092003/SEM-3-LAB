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


char stack[100];
int top = 0;

void push(char element)
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

char pop()
{
	if(top == 0)
	{
		printf("Stack is empty\n");
	}
	else{
		top -- ;
		char x = stack[top];
		stack[top] = -1;
		return x;
	}
}

void main()
{
	char s[100];
	printf("Enter a string : ");
	scanf("%s" , s);
	int n = length(s);
	
	int flag = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			push(s[i]);
		}
		else if(s[i] == ')')
		{
			char element = pop();
			if (element != '(') {flag = 1; break;}	
		}
		else if(s[i] == ']') 
		{
			char element = pop();
			if (element != '[') {flag = 1; break;}	
		}
		else if(s[i] == '}')
		{
			char element = pop();
			if (element != '{') {flag = 1; break;}	
		}
		else 
		{
			printf("Invalid input");
		}
		printf("Stack :");
		for(int i = 0 ; i < top ; i ++)
		{
			printf("%c " , stack[i]);
		}
		printf("\n");
	}
	printf("\n");
	if(flag == 0 && top == 0)
	{
		printf("VALID !");
	}
	else{
		printf("INVALID !");
	}
	printf("\n");
		
}
