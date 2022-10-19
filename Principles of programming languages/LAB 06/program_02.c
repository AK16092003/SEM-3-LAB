#include<stdio.h>

int factorial(int n)
{
	if(n == 0) return 1;
	return n*factorial(n-1);
}

int main()
{
	int n;
	printf("Enter N : ");
	scanf("%d" , &n);
	
	int ans = factorial(n);
	int n1 = n;
	printf("(recursion) %d! =  %d\n" , n,ans);
	
	int p = 1;
	while(n!= 0)
	{
		p = p*n;
		n--;
	}
	
	printf("(iterative) %d! =  %d\n" , n1,p);
	
	return 0;
		
		
}
