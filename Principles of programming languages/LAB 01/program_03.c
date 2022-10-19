#include<stdio.h>

int find_length(int n)
{
	int l = 0;
	while(n)
	{
		n= n/10;
		l++;
	}
	return l;
}

int power(int a , int b)
{
	int ans = 1;
	for(int i = 0 ; i < b ; i ++) 
		ans = ans * a;
	return ans;
}
int check_arms(int n)
{
	
	int length = find_length(n);
	int ans = 0;
	while(n)
	{
		ans += power( (n%10) , length );
		n = n / 10;
	}
	return ans;
}



void main()
{
	for(int i = 1 ; i <= 1000; i ++)
	{
		if(check_arms(i) == i)
		{
			printf("%d is armstrong number\n",i);
		}
	}
}
