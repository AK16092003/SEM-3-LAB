#include<iostream>
using namespace std;

class A
{
	public:
		int m1,m2,m3,m4,m5;
		int total;
		void input();
		int sum();
};

void A::input()
{
	cout << "Enter 5 subjects marks : \n"<<endl;
	cin >> m1 >> m2 >> m3 >>m4 >> m5;
	
}

int A::sum()
{
	total = m1+m2+m3+m4+m5;
	return total;
}


class B:public A
{
	public:
		float avg;
		char grade;
		void gradecalc();
};

void B::gradecalc()
{
	int t;
	t = sum();
	avg = t/5;
	if(avg > 90) grade = 'S';
	else if(avg > 80) grade = 'A';
	else if(avg > 70) grade = 'B';
	else if(avg > 60) grade = 'C';
	else if(avg > 50) grade = 'D';
	else if(avg > 40) grade = 'E';
	else grade = 'F';
	cout << "Grade is:  "<<grade <<endl;

}

int main()
{
	B b;
	b.input();
	b.gradecalc();
	return 0;
}
