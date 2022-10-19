#include<stdio.h>

void main()
{	// fibonacci

	int n;
	printf("Enter n: ");
	scanf("%d" , &n);
	int a = 0 , b = 1;
	int c;
	printf("%d %d ",a,b);
	for(int i = 2 ; i <= n ; i ++)
	{
		c = a+b;
		printf("%d ",c);
		a = b;
		b = c;
	}
	
	printf("\n\n%d th fibonacci number is %d\n\n" , n , c);
	
}
