#include<iostream>
using namespace std;

class STACK
{
	public:
		char *elements;
		int top;
		void push(int x);
		char pop();
		STACK();
		~STACK();
		int sz;
		bool isEmpty();
		bool isFull();
};

STACK::STACK()
{
	cout << "Created stack object "<<endl;
	cout<<"Enter size: ";
	cin >> sz;
	elements = new char[sz];
	top = 0;
}

STACK::~STACK()
{
	cout<<"Deleted stack object " <<endl;
	delete elements;
}

bool STACK::isEmpty()
{
	if(top == 0)return true;
	return false;
}

bool STACK::isFull()
{
	if(top == sz)return true;
	return false;
}


void STACK::push(int x)
{
	if(isFull())
	{
		cout << "Overflow !" << endl;
	}
	else
	{
		elements[top++] = x;
	}
}


char STACK::pop()
{
	if(isEmpty())
	{
		cout << "Underflow !" << endl;
		return -1;
	}
	else
	{
		return elements[--top];
	}
}



int main()
{
	STACK S;
	cout << "1) push "<<endl;
	cout << "2) pop "<<endl;
	cout << "3) isEmpty "<<endl;
	cout << "4) isFull "<<endl;
	cout << "5) size "<<endl;
	int ch;
	while(true)
	{
		cout<<"Enter your choice: ";
		cin >> ch;
		
		if(ch == 1)
		{
			int d;
			cout<<"Enter data : "; 
			cin >> d;
			S.push(d);
		}
		else if(ch == 2)
		{
			int d = S.pop();
			cout << "popped element : "<<d<<endl;
		}
		else if(ch == 3)
		{
			if(S.isEmpty())
			{
				cout <<"Stack is empty"<<endl;
			}
			else
			{
				cout << "Stack is not empty"<<endl;
			}
		}

		else if(ch == 4)
		{
			if(S.isFull())
			{
				cout <<"Stack is full"<<endl;
			}
			else
			{
				cout << "Stack is not full"<<endl;
			}
		
		}
		else if(ch ==5)
		{
			int sz = S.sz;
			cout << "Size : "<<sz<<endl;
		}
		else
		{
			cout << "Thank you!"<<endl;
			break;
		}
		cout<<endl;
	}
	return 0;
}
