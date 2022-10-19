#include<iostream>
using namespace std;

class A
{
	public:
		int a , b;
		int sum();
};

int A::sum()
{
	cout<<"CLass A:"<<endl;
	cout << "Sum = "<<a+b<<"\n"<<endl;
	return a+b;
}

class B
{
	public:
		int a , b;
		int difference();
};

int B::difference()
{
	cout<<"CLass B:"<<endl;
	cout << "difference = "<<a-b<<"\n"<<endl;
	return a-b;
}


class C:public A , public B
{
	public:
		int multiply();
};

int C::multiply()
{
	cout<<"Enter a and b : ";
	cin >> A::a >> A::b;
	B::a = A::a;
	B::b = A::b;
	cout<<"CLass C:"<<endl;
	cout << "Multiplication : \n"<<sum()*difference() <<"\n"<< endl;
	return sum()*difference();
}


class D:public C
{
	public:
		int p;
		int square();
		
};

int D::square()
{
	cout<<"CLass D:"<<endl;
	p = multiply();
	cout << "square = "<<p*p <<"\n"<< endl;
	return p*p;
}


class E:public C
{
	public:
		int p;
		int cube();
		
};

int E::cube()
{
	cout<<"CLass E:"<<endl;
	p = multiply();
	cout << "cube = "<<p*p*p << "\n"<<endl;
	return p*p*p;
}




int main()
{
	D d1;
	E e1;
	d1.square();
	e1.cube();
	return 0;
}
