#include<stdio.h>

int is_prime(int n)
{
	for(int j = 2 ; j < n ; j ++)
	{
		if(n%j == 0)
		{
			return 0;
		}
	}
	return 1;
}


void main()
{
	for(int i = 2 ; i <= 100 ; i ++ )
	{
		if(is_prime(i))
		{
			printf("%d is prime\n" , i);
		}
	}
}
