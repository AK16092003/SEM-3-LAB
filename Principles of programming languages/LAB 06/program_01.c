#include<stdio.h>

int fibonacci(int n)
{
	if(n == 1) return 0;
	if(n == 2) return 1;
	
	return fibonacci(n-1)+fibonacci(n-2);
}

int main()
{
	int n;
	printf("Enter N : ");
	scanf("%d" , &n);
	
	int ans = fibonacci(n);
	int n1 = n;
	printf("(recursion) %d th term =  %d\n\n" , n,ans);
	
	int a = 0 , b = 1;
	printf("%d %d ",a , b);
	int c = 0;
	n-=2;
	
	while(n!= 0)
	{
		c = a + b;
		printf("%d ",c);
		a = b;
		b = c;
		n--;
	}
	
	printf("\n(iterative) %d th term =  %d\n" , n1,c);
	
	return 0;	
		
}
