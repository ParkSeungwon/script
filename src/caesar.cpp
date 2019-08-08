#include<iostream>
#include<string>
using namespace std;

string enc(string m, int k) {
	for(char &c : m) c += k;
	return m;
}
string dec(string m, int k) {
	for(char &c : m) c -= k;
	return m;
}
int main()
{
	string m = "We will attack tommorow morning";
	cout << (m = enc(m, 1)) << endl;
	cout << dec(m, 1) << endl;
}

