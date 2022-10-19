#include<stdio.h>

int gcd(int a , int b)
{
	if(a == 0) return b;
	return gcd(b%a , a);
}

int main()
{
	int a , b;
	printf("Enter 2 numbers : ");
	scanf("%d %d" , &a , &b);
	int a1 = a , b1 = b;
	int g = gcd(a , b);
	
	printf("\nGcd of 2 numbers (recursion) : %d\n" , g);
	printf("\nLcm of 2 numbers             : %d\n" , a*b/g);
	
	while(a!= 0)
	{
		int t = b%a;
		int u = a;
		a = t;
		b = u;
	}
	
	printf("\nGcd of 2 numbers (iterative) : %d\n" , b);
	printf("\nLcm of 2 numbers             : %d\n" , a1*b1/b);
	
	return 0;
		
		
}
