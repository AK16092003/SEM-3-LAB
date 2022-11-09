#include<stdio.h>
#include<stdlib.h>

int length(char *a)
{
	for(int i = 0 ; i < 100 ; i ++)
	{
		if(a[i] == '\0')
			return i;
	}
	return 0;
}



int main()
{
	printf("Enter main string : ");
	char main_str[100];
	scanf("%s" , main_str);
	
	printf("Enter pattern  : ");
	char pattern[100];
	scanf("%s" , pattern);
	
	int n1 = length(main_str);
	int n2 = length(pattern);
	
	printf("\n\nLength of main string : %d\n" , n1);
	printf("Length of pattern     : %d\n" , n2);
	
	int pre_cal[n2];
	pre_cal[0] = 0;
	int p1 = 0;
	for(int i = 1 ; i < n2 ; i ++)
	{
		if(pattern[i] == pattern[p1])
		{
			pre_cal[i] = p1+1;
			p1++;
		}
		else
		{
			p1 = 0;
			pre_cal[i] = 0;
		}
	}
	
	printf("\n\nPattern Array : \n");
	for(int i = 0 ; i < n2 ; i ++)
	{
		printf("%d " , pre_cal[i]);
	}
	printf("\n\n");
	
	int p2 =  0;
	p1 = 0;
	int flag = 0;
	while(p1 < n1)
	{
		printf("i = %d , j = %d , %c %c " , p1 , p2 , main_str[p1] , pattern[p2]);
		if(main_str[p1] == pattern[p2])
		{
			p2++;
			p1++;
			printf("match \n");
		}
		else
		{
			if(p2 == 0) {p2 = 0; p1++;}
			else p2 = pre_cal[p2-1];
			printf("doesnt match \n");
		}	
		if(p2 == n2) {printf("\nfound !\n");flag = 1;break;}
	}
	
	if(flag == 0)
	{
		printf("pattern not found ! \n\n");
	}
	
	return 0;
}
