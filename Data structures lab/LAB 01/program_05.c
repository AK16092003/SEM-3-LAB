#include<stdio.h>

void main()
{
	// pascal triangle
	
	int n;
	printf("\n");
	printf("Enter n = ");
	scanf("%d" , &n);
	
	for(int i = 1 ; i <= n+1 ; i ++)
	{
		int start_element = 1;
		for(int k = 0 ; k < n - i + 1 ; k ++)
		{
			printf(" ");
		}
		for(int j = 0 ; j < i ; j ++)
		{
			printf("%d " , start_element);
			start_element = (start_element * (i - j - 1))/(j+1);
		}
		printf("\n");
	
	}
	printf("\n\n");

}
