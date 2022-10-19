#include<stdio.h>
#include<stdlib.h>

int main()
{
	// matrix subtraction
	int r ,c;
	printf("Enter number of rows and columns : ");
	scanf("%d %d"  ,&r , &c);
	
	int **a = (int **) malloc(r*sizeof(int*));
	int **b = (int **) malloc(r*sizeof(int*));
	int **dif = (int **) malloc(r*sizeof(int*));
	
	for(int i = 0 ; i < r ; i ++)
	{
		a[i] = (int *)malloc(c*sizeof(int));
		b[i] = (int *)malloc(c*sizeof(int));
		dif[i] = (int *)malloc(c*sizeof(int));
	}
	printf("Enter matrix A :\n");
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			scanf("%d" , &a[i][j]);
		}
	}
	
	
	printf("Enter matrix B :\n");
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			scanf("%d" , &b[i][j]);
		}
	}
	
	
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			dif[i][j] = a[i][j] - b[i][j];
		}
	}
	
	
	printf("Difference Matrix :\n");
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			printf("%d " ,dif[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 0 ; i < r ; i ++)
	{
		free(a[i]);
		free(b[i]);
		free(dif[i]);
	}
	free(a);
	free(b);
	free(dif);
	
	
	return 0;
} 
