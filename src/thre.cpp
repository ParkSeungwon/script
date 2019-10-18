#include<atomic>
#include <iostream>
#include <thread>
#include<vector>
using namespace std;
 
atomic_flag flag = ATOMIC_FLAG_INIT;
atomic<bool> ready{false};
int r= 1;

void th(int k) 
{
	while(!ready) this_thread::yield();
	for(volatile int i=0; i<1000000; i++) ;
	while(flag.test_and_set());
	cout << k << " ranked " << r++ << endl;
	flag.clear();
}
 
int main() 
{
	vector<thread> v;
	for(int i=0; i<10; i++) v.push_back(thread{th, i});
	ready = true;
	for(auto &a : v) a.join();
}
