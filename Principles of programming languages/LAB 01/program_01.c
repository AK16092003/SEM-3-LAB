#include<stdio.h>

void main()
{

	int array[3];
	float arr[3];

	for(int i = 0 ; i < 3 ; i ++)
	{
		printf("Enter a integer %d : ",(i+1) ); scanf("%d" , &array[i]);
	}

	int max_el = array[0];
	int min_el = array[0];

	for(int i = 1 ; i < 3 ; i ++)
	{
		if(array[i] > max_el) max_el = array[i];
		if(array[i] < min_el) min_el = array[i];
	}
	printf("Max = %d \nMin = %d\n" , max_el , min_el );



	for(int i = 0 ; i < 3 ; i ++)
	{
		printf("Enter a float %d : ",(i+1) ); scanf("%f" , &arr[i]);
	}

	float max = arr[0];
	float min = arr[0];

	for(int i = 1 ; i < 3 ; i ++)
	{
		if(arr[i] > max) max = arr[i];
		if(arr[i] < min) min = arr[i];
	}
	printf("Max = %f \nMin = %f\n" , max , min );




}
