#include<vector>
#include<iostream>
#include<tuple>
using namespace std;

template<int N, class T> void print_tuple(const T &t) {
	if constexpr(N >1) print_tuple<N -1>(t);
	cout << get<N -1>(t) << ' ';
}

int main()
{
	int k = 3;
	vector v = {1,2,3};
	tuple t{"hello", 3.4, 3, false, 'c'};
	print_tuple<5>(t);
	cout << k;
}

