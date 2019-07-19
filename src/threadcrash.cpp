#include<thread>
#include<iostream>
using namespace std;

void f() {
	cout << 16 << endl;
}

int main()
{
	cout << hex << 16 << endl;
	cout << 16 << endl;
	f();
	thread th{[]() { this_thread::sleep_for(5s); } };
	if(th.joinable()) cout << "joinable" << endl;
	th.join();
}

