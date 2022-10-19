#include<stdio.h>

struct student
{
	char name[100];
	int marks[5];
	int rollnumber;
	int total;
	float avg;
};


int main()
{
	printf("Create record of students ");
	int n;
	scanf("%d" , &n);
	struct student s[n];
	for(int i = 0 ; i < n ; i ++)
	{
		printf("Student %d\n" , (i+1));
		printf("Enter name :");
		scanf("%s" , (s[i].name));
		printf("Enter roll number :");
		scanf("%d" , &(s[i].rollnumber));
		
		float total = 0;
		
		for(int j = 0 ; j < 5; j ++)
		{
			printf("Subject %d marks (out of 100) :",(j+1));
			scanf("%d" , &(s[i].marks[j]));
			total = total + s[i].marks[j];
		}	
		
		s[i].total = total;
		s[i].avg = total / 5;
	}
	
	
	printf("\n\n");
	for(int i = 0 ; i < n ; i ++)
	{
		printf("Rollnumber %d : Total : %d  Average : %.2f ",s[i].rollnumber , s[i].total , s[i].avg);
		float avg = s[i].avg;
		     if(avg > 90) printf("Grade : S");
		else if(avg > 80) printf("Grade : A");
		else if(avg > 70) printf("Grade : B");
		else if(avg > 60) printf("Grade : C");
		else if(avg > 50) printf("Grade : D");
		else if(avg > 40) printf("Grade : E");
		else 		   printf("Grade : F");
		printf("\n");
	}
	return 0;
}
