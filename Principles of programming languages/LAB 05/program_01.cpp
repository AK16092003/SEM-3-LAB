// max 2 number

#include<iostream>
using namespace std;

template <class T>
T maxi(T a , T b)
{
	T c = (a > b)?a:b;
	return c; 
		
}

int main()
{
	int a , b;
	cout << "Enter 2 integers :";
	cin >> a >> b;
	cout << "maximum : "<<maxi(a,b) << endl;
	
	float c , d;
	cout << "Enter 2 floating numbers :";
	cin >> c >> d;
	cout << "maximum : "<<maxi(c , d) << endl;
	
	char e , f;
	cout << "Enter 2 characters  :";
	cin >> e >> f;
	cout << "maximum : "<<maxi(e , f) << endl;
	return 0;
}
