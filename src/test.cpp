#include<optional>
#include<iostream>
using namespace std;

optional<string> f(bool i) {
	if( i) return "" ;
	else return {};
}
int main() {
	char c[] = {0x20, 0x0e, 0x74, 0x6c, 0x73, 0x31, 0x33, 0x20, 0x66, 0x69, 0x6e, 0x69, 0x73, 0x68, 0x65, 0x64, 0x00};
	cout << c << endl;
//	for(char a : c) cout << hex << +a << ':' << a << ',';

	if(f(true)) cout << "\"\"" << endl;
	if(f(false)) cout << "{}" << endl;
}

