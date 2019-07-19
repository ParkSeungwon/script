#include<iostream>
using namespace std;

int powm(int b, int e, int m) {
	int r = 1;
	for(int i=0; i<e; i++) {
		r *= b;
		r %= m;
	}
	return r;
}

int main() {
	cout << powm(2, 1000, 24);
}
