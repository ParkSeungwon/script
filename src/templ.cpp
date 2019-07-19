#include<iostream>
using namespace std;

int main()
{
	const char (*p)[40], (*(q[40]))[100];
	cout << sizeof(p) << endl;
	cout << (p+1)  << ' ' << p << endl;
	cout << sizeof(q) << endl;
	cout << (*q+1)  << ' ' << *q << endl;
}
