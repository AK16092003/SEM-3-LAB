#include<stdio.h>

void main()
{
	// check for palindrome
	
	int n;
	printf("Enter a number : ");
	scanf("%d" , &n);
	int reverse = 0;
	
	int n1 = n;
	while(n1)
	{
		int d = n1%10;
		reverse = reverse*10 + d;
		n1 = n1/10;
	}
	
	printf("Reverse number = %d\n" , reverse);
	if(reverse == n)
	{
		printf("Yes , it is a palindrome !");
	}
	else{
		printf("No , it is not a palindrome !");
	}
	printf("\n\n");

}
