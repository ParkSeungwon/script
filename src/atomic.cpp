#include<iostream>
#include<thread>
#include<atomic>
using namespace std;

//use atomic instead of condition variable
atomic<int> a = 0;
int k = 0;

void print_zero(int n) {
	bool flag = true;
	while(k < n) {
		while(a) this_thread::yield();
		k++;
		cerr << 0;
		if(flag) a++;
		else a--;
		flag = !flag;
	}
	cerr << "a";
}
void print_odd(int n) {
	while(k < n-1) {
		while(a != 1) this_thread::yield();
		cerr << k;
		a--;
	}
	cerr << "b";
}
void print_even(int n) {
	while(k < n-1) {
		while(a != -1) this_thread::yield();
		cerr << k;
		a++;
	}
	cerr << "c";
}
int main(int ac, char **av) {
	int k = atoi(av[1]);
	thread t1{print_zero, k}, t2{print_odd, k}, t3{print_even, k};
	t1.join(); t2.join(); t3.join();
}

