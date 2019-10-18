#include<iostream>
#include<vector>
#include<atomic>
#include<thread>
#include<condition_variable>
using namespace std;

int fib(int n) {
	int a[3] = {0, 1, 1};
	for(int i=3; i<=n; i++) a[i%3] = a[(i+1)%3] + a[(i+2)%3];
	return a[n%3];
}

atomic<int> k{0};
condition_variable cv, zero, even, odd;
bool zero_turn = true;
mutex toilet;
void printzr(int n) {
	unique_lock<mutex> lck{toilet, defer_lock};
	while(k < n) {
		lck.lock();
		while(!zero_turn) zero.wait(lck);
		k++;
		cerr << 0;
		zero_turn = false;
		lck.unlock();
		if(k %2 == 0) even.notify_one();
		else odd.notify_one();
	}
	even.notify_one();
	odd.notify_one();
}
void printeven(int n) {
	unique_lock<mutex> lck{toilet, defer_lock};
	while(k < n) {
		lck.lock();
		while(zero_turn) even.wait(lck);
		if(k % 2 == 0) cerr << k;
		zero_turn = true;
		lck.unlock();
		zero.notify_one();
	}
	zero_turn = false;
}
void printodd(int n) {
	unique_lock<mutex> lck{toilet, defer_lock};
	while(k < n) {
		lck.lock();
		while(zero_turn) odd.wait(lck);
		if(k%2 == 1) cerr << k;
		zero_turn = true;
		lck.unlock();
		zero.notify_one();
	}
	zero_turn = false;
}

int main(int ac, char **av) {
	thread th1{printeven, atoi(av[1])}, th2{printodd,atoi(av[1])}, 
		   th3{printzr, atoi(av[1])};
	th1.join();
	th2.join();
	th3.join();
}
