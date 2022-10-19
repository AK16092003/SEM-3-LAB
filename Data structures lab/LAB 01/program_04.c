#include<stdio.h>

void main()
{
	// nth term in fibonacci series
	
	int n;
	printf("\n");
	printf("Enter n = ");
	scanf("%d" , &n);
	
	int a = 0;
	int b = 1;
	int c = 1;
	printf("%d %d ",a,b);
	for(int i = 2 ; i < n ; i ++)
	{
		c = a+b;
		printf("%d " , c);
		a = b;
		b = c;
	}
	printf("\n%d th term in fibonacci series is %d" , n , c);
	printf("\n\n");

}
