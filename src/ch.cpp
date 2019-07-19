#include<arpa/inet.h>
#include<iostream>
using namespace std;

union {
	unsigned char cA[4] = { 0x00, 0x09, 0x27, 0xc0 };
	int k;
} u;

int main() 
{
	cout << htonl(u.k) << endl;
	cout << u.k << endl;
	char a = 'a';
	for(char c; cin >> c;) cout << a << endl;
	return htonl(u.k);
}
