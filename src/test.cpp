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
#include<type_traits>
#include<mutex>
using namespace std;

int main()
{
	string s = "\u1100\u1161\u11a8";
	if(s != "각") cout << s << " is not 각" << endl;
	ofstream f{s};
	f << 'a';
	s = "\uac01";
	if(s == "각") cout << s << " is 각" << endl;
}
