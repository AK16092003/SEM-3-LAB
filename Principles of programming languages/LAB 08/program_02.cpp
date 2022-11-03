#include<iostream>
using namespace std;


class Matrix
{
	public:
		int row1 , row2;
		int col1 , col2;
		int *A , *B;
		void GetInput();
};


void Matrix :: GetInput()
{
	cout << "Enter row and column of matrix 1 : ";
	cin >> row1 >> col1;
	cout << "Enter matrix elements : "<<endl;
	A = new int[row1 * col1];
	for(int i = 0 ; i < row1*col1 ; i ++)
	{
		cin >> A[i];
	}
	
	cout << "Enter row and column of matrix 2 : ";
	cin >> row2 >> col2;
	cout << "Enter matrix elements : "<<endl;
	B = new int[row2 * col2];
	for(int i = 0 ; i < row2*col2 ; i ++)
	{
		cin >> B[i];
	}
	
}


class ADD : public Matrix
{
	public:
		int *C;
		void addition();
};

void ADD::addition()
{
	GetInput();
	
	if(row1 == row2 && col1 == col2)
	{
		C = new int[row1*col1];
		for(int i = 0 ; i < row2*col2 ; i ++)
		{
			C[i] = A[i] + B[i];
		}
		cout<<"\n\nAddition : "<<endl;
		for(int i = 0 ; i < row1 ; i ++)
		{
			for(int j = 0 ; j < col1 ; j ++)
			{
				cout << C[i*col1 + j]<<" ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Dimensions are Incorrect !" << endl;
	}
	
}


class SUB : public Matrix
{
	public:
		int *C;
		void subtraction();
};

void SUB::subtraction()
{
	GetInput();
	
	if(row1 == row2 && col1 == col2)
	{
		C = new int[row1*col1];
		for(int i = 0 ; i < row2*col2 ; i ++)
		{
			C[i] = A[i] - B[i];
		}
		cout<<"\n\nSubtraction : "<<endl;
		for(int i = 0 ; i < row1 ; i ++)
		{
			for(int j = 0 ; j < col1 ; j ++)
			{
				cout << C[i*col1 + j]<<" ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Dimensions are Incorrect !" << endl;
	}
	
}


class MUL : public Matrix
{
	public:
		int *C;
		void multiplication();
};

void MUL::multiplication()
{
	GetInput();
	
	if(row2 == col1)
	{
		C = new int[row1*col2];
		for(int i = 0 ; i < row1 ; i ++)
		{
			for(int j = 0 ; j < col2 ; j ++)
			{
				C[i*col2 + j] = 0;
				for(int k = 0 ; k < row2 ; k ++)
				{
					C[i*col2 + j] += A[i*col1 + k]*B[k*col2 + j];
				}
			}
		}
		cout<<"\n\nMultiplication : "<<endl;
		for(int i = 0 ; i < row1 ; i ++)
		{
			for(int j = 0 ; j < col2 ; j ++)
			{
				cout << C[i*col2 + j]<<" ";
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Dimensions are Incorrect !" << endl;
	}
	
}

int main()
{
	ADD a;
	a.addition();
	
	SUB b;
	b.subtraction();
	
	MUL c;
	c.multiplication();
	
	return 0;
}
