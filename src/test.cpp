#include<iostream>
using namespace std;

struct A {
	A& operator=(int n) {
		a_ = n;
	}
	int a_;
};

struct B : A {
	
};
int main()
{
	A a;
	a = 3;
	cout << a.a_ << endl;
	B b;
	b.A::operator=( 3);
}
