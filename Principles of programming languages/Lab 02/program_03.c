#include<stdio.h>

void main()
{	
	int odd=0, even=0;
	int count = 0;
	for(int i = 2 ; i <=100 ; i ++)
	{
		int flag = 0;
		for(int j = 2 ; j < i ; j ++)
		{
			if(i%j == 0)
			{
				flag = 1;
				break;
			}
		}
		
		if(flag == 0)
		{
			count ++;
			if(count%2 == 1) {printf("Odd prime  : %d\n" , i);odd+=i;}
			if(count%2 == 0) {printf("Even prime : %d\n" , i);even+=i;}
			
		}
	}
	
	printf("Sum of odd prime : %d\n" , odd);
	printf("Sum of even prime : %d\n" , even);
}
