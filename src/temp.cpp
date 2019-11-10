#include<iostream>
using namespace std;

template<class T> T pi = T{3.1415};
template<class T> class A 
{
	T a;
};

template<class T> int func(T a) {
	return 3;
}

template<int Value> constexpr int fib = fib<Value - 1> + fib<Value -2>;
template<> constexpr int fib<0> = 0;
template<> constexpr int fib<1> = 1;

//mind blowing
template<class T, class U> constexpr bool is_= false;
template<class T> constexpr bool is_<T, T> = true;

template<class T> auto f = [](const T& l, const T& r) {
	return l + r;
};

template<class T> auto f2(T l, T r) {
	return l + r;
}

int main() {
	cout << pi<float> << endl;
	cout << func(3) << endl;
	A<int> a;
	cout <<	fib<10> << endl;
	cout << is_<int, int> << endl;
	cout << f<int>(3.4, 2.5) << endl;
	cout << f2<float>(3.4, 2.5) << endl;
}

