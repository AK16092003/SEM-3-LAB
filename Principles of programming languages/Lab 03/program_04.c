#include<stdio.h>
#include<stdlib.h>

int main()
{
	// linear search
	int n;
	printf("Enter number of elements of A: ");
	scanf("%d"  ,&n);
	int *array = (int *) malloc(sizeof(int) * n);
	
	for(int i = 0 ; i < n ; i ++)
	{
		printf("Enter data %d : " , (i+1));
		scanf("%d" , &array[i]);
	}
	int x;
	printf("Enter search element : ");
	scanf("%d" , &x);
	int flag = 0;
	for(int i = 0 ; i < n ; i ++)
	{
		if(x == array[i])
		{
			flag = 1;
			printf("found at : %d\n" , i);
		}
	}
	if(flag == 0)
	{
		printf("\nThe element is not found!\n\n");
	}
	free(array);
} 
