#include<nettle/curve25519.h>
#include<iomanip>
#include<iostream>
using namespace std;

int main() {
	uint8_t result[32], one[32], nine[32];
	for(auto &i : one) i = 0;
	one[0] = 1;
	for(auto &i : nine) i = 0;
	nine[0] = 9;
	curve25519_mul_g(result, one);
	for(auto it = rbegin(result); it != rend(result); it++) cout << hex << +*it;
	cout << endl;
	curve25519_mul(result, one, nine);
	for(auto i : result) cout << hex << +i;
	cout << endl;
}
