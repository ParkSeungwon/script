#include<fstream>
#include<iostream>
#include<functional>
#include<string>
#include<sstream>
#include<cctype>
#include<algorithm>
#include<map>
#include<random>
#include<complex>
#include<csignal>
#include<thread>
#include<mutex>
using namespace std;

const char *p[][2] = {
	{".html", "text/html"},
	{".css", "text/css"},
	{".mp3", "web/audio"}
};
mutex mtx;
int f(int a) {
	static int k=0;
	int i;
	for( i=0; i<a; i++) k += i;
	lock_guard lock{mtx};
	cout << k << endl;
}
int main() {
	string s = "a.html";
	cout << s.substr(s.rfind('.'), 4) << endl;
}
