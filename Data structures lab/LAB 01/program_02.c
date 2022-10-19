#include<stdio.h>

void main()
{
	// print second maximum element
	int n = 10;
	int array[10];

	for(int i = 0 ; i <n ; i++)
	{
		printf("Enter element %d = " , (i+1));
		scanf("%d" , &array[i]);
	}

	int max_element = 0;
	int second_max_element = 0;
	
	for(int j = 0 ; j < n ; j ++)
	{
		if(max_element < array[j])
		{
			second_max_element = max_element;
			max_element = array[j];
		}
		else if(second_max_element < array[j])
		{
			second_max_element = array[j];
		}
	}

	printf("second maximum element : %d\n" , second_max_element);


}
