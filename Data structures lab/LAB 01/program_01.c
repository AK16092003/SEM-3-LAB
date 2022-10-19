#include<stdio.h>

void main()
{
	// print maximum element
	int n = 10;
	int array[10];

	for(int i = 0 ; i <n ; i++)
	{
		printf("Enter element %d = " , (i+1));
		scanf("%d" , &array[i]);
	}

	int max_element = array[0];
	for(int j = 1 ; j < n ; j ++)
	{
		if(max_element < array[j])
		{
			max_element = array[j];
		}
	}

	printf("Maximum element : %d\n" , max_element);


}
