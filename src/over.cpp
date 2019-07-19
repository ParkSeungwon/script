#include<sstream>
#include<iostream>
using namespace std;
struct A {
	int k=1;
};
ostream& operator<<(ostream& o, const A& a) {
	o << a.k << endl;
	return o;
}
stringstream& operator<<(stringstream& ss, const A& a) {
	ss << a.k+1;
	return ss;
}
int main()
{
	A a;
	cout << a;
	stringstream ss;
	ss << a;
	cout << ss.str() << endl;
}



