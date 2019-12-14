#include<iostream>
using namespace std;

int main(int ac, char **av) {
	const char *p = "abcd";
	cout << *p++ << *p++ << *p++;
	return 1;
}
