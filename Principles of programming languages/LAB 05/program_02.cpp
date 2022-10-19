// max 2 number

#include<iostream>
using namespace std;

template <class T>
void sorting(T a[] , int n)
{
	for(int i = 0 ; i < n ; i ++)
	{
		for(int j = 0 ; j < n-i-1 ; j++)
		{
			if(a[j] > a[j+1])
			{
				T temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
	
	cout << "Sorted array : ";
	for(int i = 0 ; i < n ; i ++)
	{
		cout << a[i]<<" ";
	}
	cout<<"\n\n";
}

int main()
{
	int n;
	//integer array sorting
	
	cout << "Enter size of integer array : ";
	cin >> n;
	
	int arr1[n];
	for(int i = 0 ; i < n ; i ++)
	{
		cout << "Enter data : "<< (i+1) << " : ";
		cin >> arr1[i];
	}
	
	sorting(arr1 , n);
	
	//float array sorting
	
	cout << "Enter size of float array : ";
	cin >> n;
	
	float arr2[n];
	for(int i = 0 ; i < n ; i ++)
	{
		cout << "Enter data : "<< (i+1) << " : ";
		cin >> arr2[i];
	}
	
	sorting(arr2 , n);
	
	cout << "Enter size of character array : ";
	cin >> n;
	
	//character array sorting
	
	char arr3[n];
	for(int i = 0 ; i < n ; i ++)
	{
		cout << "Enter data : "<< (i+1) << " : ";
		cin >> arr3[i];
	}
	
	sorting(arr3 , n);
	
	
	
	return 0;
}
