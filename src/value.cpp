#include<iostream>
using namespace std;

template<class T> struct Val 
{
	Val(const T &t) : val_{t} { }
	bool operator<(const T& t) const {
		return first_compare_ ? val_ < t : false;
	}
	bool operator<=(const T &t) const {
		return first_compare_ ? val_ < t || val_ == t : false;
	}
	T val_;
	bool first_compare_ = true;
};

template<class T> Val<T>& operator<(T t, Val<T> &&val) {
	val.first_compare_ = (t < val.val_);
	return val;
}
template<class T> Val<T>& operator<=(T t, Val<T> &&val) {
	val.first_compare_ = (t <= val.val_);
	return val;
}

int main() {
	int x[] = {1,2,3,4,5,6,7,8};
	for(int i : x) if(3 < Val{i} <= 5) cout << i << " is between (3,5]" << endl;
}
