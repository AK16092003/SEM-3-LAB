#include<stdio.h>

struct employee
{
	char name[100];
	int empid;
	float basicpay;
	float salary;
	float da;
	float hsa;
	float year_income; 
};


int main()
{
	printf("Create record of employees ");
	int n ;
	scanf("%d" , &n);
	struct employee s[n];
	
	for(int i = 0 ; i < n ; i ++)
	{
		printf("Employee %d\n" , (i+1));
		printf("Enter name :");
		scanf("%s" , (s[i].name));
		printf("Enter employee number :");
		scanf("%d" , &(s[i].empid));
		printf("Enter basic pay : ");
		scanf("%f" , &(s[i].basicpay));
		
		s[i].da = s[i].basicpay * 0.38;
		s[i].hsa = s[i].basicpay * 0.18;
		s[i].salary = s[i].da + s[i].hsa + s[i].basicpay;
		s[i].year_income = s[i].salary * 12;
		
		
	}
	
	
	printf("\n\n");
	printf("DATA :\n-----------------------------------------------------------\n");
	
	for(int i = 0 ; i < n ; i ++)
	{
		
		printf("Employee %d\n" , (i+1));
		printf("Name : %s\n" , s[i].name);
		printf("Employee Id : %d\n" , s[i].empid);
		printf("Basic Pay : %.2f\n" , s[i].basicpay);
		printf("DA : %.2f\n" , s[i].da);
		printf("HSA : %.2f\n" , s[i].hsa);
		printf("Salary : %.2f\n" , s[i].salary);
		printf("Yearly Income : %.2f\n" , s[i].year_income);
		
		float y = s[i].year_income;
		float it = y;
		
		if(y > 1000000) it*=0.2;
		else if(y > 800000) it*=0.15;
		else if(y > 600000) it*=0.10;
		else if(y > 400000) it*=0.07;
		else		it*=0.02 ;
		
		printf("Income Tax : %f\n" , it);
		
		
		printf("-----------------------------------------------------------\n");
	}	
	return 0;
}
