#include<stdio.h>

void main()
{	// factorial
	int n;
	printf("Enter n: ");
	scanf("%d" , &n);
	int ans = 1;
	for(int i = 2 ; i <= n ; i ++) ans*=i;
	printf("\n%d! = %d\n\n",n,ans);
}
