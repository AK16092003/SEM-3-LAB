#include<iostream>
using namespace std;

class A
{
	public:
		string s;
		A();
		~A();	
};

A::A()
{
	cout << "Class A - object created "<<endl;
}

A::~A()
{
	cout << "Class A - object destroyed"<<endl;
}


class B
{
	public:
		string s;
		B();
		~B();	
};

B::B()
{
	cout << "Class B - object created "<<endl;
}

B::~B()
{
	cout << "Class B - object destroyed"<<endl;
}

class C:public A , public B
{
	public:
		string s;
		C();
		~C();
};



C::C()
{
	cout << "Class C - object created" << endl;
	cout << "Enter string 1 : ";
	cin >> A::s;
	cout << "Enter string 2 : ";
	cin >> B::s;
	C::s = A::s + B::s;
	cout << "Concatenated string : " << C::s << endl;
}

C::~C()
{
	cout << "Class C - object destroyed " << endl;
}
class D:public C
{
	public:
		D();
		~D();
		void palindrome_check();
};

void D::palindrome_check()
{
	string s1 = "";
	int n = s.length();
	for(int i = 0 ; i < n ; i ++)
	{
		s1 = s1 + s[n-i-1];
	}
	if(s1 == s)
	{
		cout << "Yes , it is a palindrome ! "<<endl;
	}
	else
	{
		cout << "No , it is not a palindrome !"<<endl;
	}
}
D::D()
{
	cout << "Class D - object created "<<endl;
}

D::~D()
{
	cout << "Class D - object destroyed"<<endl;
}



int main()
{

	D d;
	d.palindrome_check();
	return 0;
	
}
