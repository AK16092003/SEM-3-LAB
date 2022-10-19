#include<stdio.h>
#include<stdlib.h>

int main()
{
	// matrix multipliation
	int r ,c , r1 , c1;
	printf("Enter number of rows and columns of A: ");
	scanf("%d %d"  ,&r , &c);
	printf("Enter number of rows and columns of B: ");
	scanf("%d %d"  ,&r1 , &c1);
	
	if(c == r1)
	{
		int *a = (int *) malloc(r*c*sizeof(int));
		int *b = (int *) malloc(r*c*sizeof(int));
		int *mul = (int *) malloc(r*c*sizeof(int));

		printf("Enter matrix A :\n");
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c ; j ++)
			{
				scanf("%d" , a + i*c + j);
			}
		}
		
		
		printf("Enter matrix B :\n");
		for(int i = 0 ; i < r1 ; i ++)
		{
			for(int j = 0 ; j < c1 ; j ++)
			{
				scanf("%d" , b + i*c + j);
			}
		}
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c1 ; j ++)
			{
				*(mul +i*c + j) = 0;
			}
		}
		
		// multiplication
		
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c1 ; j ++)
			{
				for(int k = 0 ; k < c ; k ++)
					*(mul +i*c + j) += (*(a +i*c + k))*(*(b+k*c +j));
			}
		}
		
		
		printf("Multiplication Matrix :\n");
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c1 ; j ++)
			{
				printf("%d " ,*(mul + i*c + j));
			}
			printf("\n");
		}
		
		free(a);
		free(b);
		free(mul);
		
		
		return 0;
	}
	else
	{
		printf("\nRow of Matrix A is not equal to column of matrix B\n");
		printf("Matrix multiplication is not possible\n\n");
	}
} 
