#include<iostream>
#include<stdlib.h>
using namespace std;


template<class T>
T* input(T* mat , int r , int c)
{
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			cout << "Enter "<<i<<" "<<j<<" = ";
			cin >>*(mat + i*c + j);
		}
	}
	return mat;
}
template<class T>
void add(T *a , T *b , int r , int c)
{
	T *sum = (T*) malloc(r*c*sizeof(T));
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			*(sum+i*c+j) = *(a+i*c+j) + *(b+i*c+j);
		}
	}
	cout << "\nSUM : "<<endl;
	for(int i = 0 ; i < r; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			cout << *(sum + i*c + j) <<" ";
		}
		cout << endl;
	}
	cout<<endl;
	free(sum);
}


template<class T>
void sub(T *a , T *b , int r , int c)
{
	T *dif = (T*) malloc(r*c*sizeof(T));
	for(int i = 0 ; i < r ; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			*(dif+i*c+j) = *(a+i*c+j) - *(b+i*c+j);
		}
	}
	cout << "\nDIFFERENCE : "<<endl;
	for(int i = 0 ; i < r; i ++)
	{
		for(int j = 0 ; j < c ; j ++)
		{
			cout << *(dif+ i*c + j) <<" ";
		}
		cout << endl;
	}
	cout<<endl;
	free(dif);
}



template<class T>
void mul(T *a , T *b , int r , int c , int r1 , int c1)
{
	if(c != r1)
	{
		cout << "INVALID MATRIX SIZE " <<endl;
	}
	else
	{
		
		T *mul = (T*) malloc(r*c1*sizeof(T));
		for(int i = 0 ; i < r ; i ++)
		{
			for(int j = 0 ; j < c1 ; j ++)
			{	
			        *(mul+i*c+j) = 0;
				for(int k = 0 ; k < c ; k ++)
				{
					*(mul+i*c+j) += (*(a+i*c+k))*(*(b+k*c1+j));
				}
			}
		}
		cout << "\nMULTIPLICATION : "<<endl;
		for(int i = 0 ; i < r; i ++)
		{
			for(int j = 0 ; j < c ; j ++)
			{
				cout << *(mul+ i*c + j) <<" ";
			}
			cout << endl;
		}
		cout<<endl;
		free(mul);
	}
}




int main()
{

	int r, c , r1 , c1;
	int *a , *b;
	cout<<"INTEGER ARRAY"<<endl;
	cout<<"ENTER ROW AND COL : "; cin >> r >> c;
	a =  (int*) malloc(r*c*sizeof(int));
	b =  (int*) malloc(r*c*sizeof(int));
	cout<<"INPUT MATRIX A"<<endl; a = input(a , r , c);
	cout<<"INPUT MATRIX B"<<endl; b = input(b , r , c);
	add(a , b , r , c);
	
	
	cout<<"ENTER ROW AND COL : "; cin >> r >> c;
	a =  (int*) malloc(r*c*sizeof(int));
	b =  (int*) malloc(r*c*sizeof(int));
	cout<<"INPUT MATRIX A"<<endl; a = input(a , r , c);
	cout<<"INPUT MATRIX B"<<endl; b = input(b , r , c);
	sub(a , b , r , c);
	
	
	cout<<"ENTER ROW AND COL MAT 1: "; cin >> r >> c;
	cout<<"ENTER ROW AND COL MAT 2: "; cin >> r1 >> c1;
	a =  (int*) malloc(r*c*sizeof(int));
	b =  (int*) malloc(r1*c1*sizeof(int));
	cout<<"INPUT MATRIX A"<<endl; a = input(a , r , c);
	cout<<"INPUT MATRIX B"<<endl; b = input(b , r1 , c1);
	mul(a , b , r , c , r1 , c1);
	
	float *e , *d;
	
	cout<<"FLOAT ARRAY"<<endl;
	cout<<"ENTER ROW AND COL : "; cin >> r >> c;
	e =  (float*) malloc(r*c*sizeof(float));
	d =  (float*) malloc(r*c*sizeof(float));
	cout<<"INPUT MATRIX A"<<endl; e = input(e , r , c);
	cout<<"INPUT MATRIX B"<<endl; d = input(d , r , c);
	add(e , d , r , c);
	
	
	cout<<"ENTER ROW AND COL : "; cin >> r >> c;
	e =  (float*) malloc(r*c*sizeof(float));
	d =  (float*) malloc(r*c*sizeof(float));
	cout<<"INPUT MATRIX A"<<endl; e = input(e , r , c);
	cout<<"INPUT MATRIX B"<<endl; d = input(d , r , c);
	sub(e , d , r , c);
	
	
	cout<<"ENTER ROW AND COL MAT 1: "; cin >> r >> c;
	cout<<"ENTER ROW AND COL MAT 2: "; cin >> r1 >> c1;
	e =  (float*) malloc(r*c*sizeof(float));
	d =  (float*) malloc(r1*c1*sizeof(float));
	cout<<"INPUT MATRIX A"<<endl; e = input(e , r , c);
	cout<<"INPUT MATRIX B"<<endl; d = input(d , r1 , c1);
	mul(e , d , r , c , r1 , c1);
	
	
	
	
}
