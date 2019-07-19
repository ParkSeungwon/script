#include<fstream>
#include<vector>
#include<string>
#include<iostream>
using namespace std;


string get_certificate_core(istream& is) {//if certificate has no -----END hang..
	string s, r;
	while(s != "-----BEGIN") if(!(is >> s)) return r;//no more certificate
	getline(is, s);
	for(is >> s; s != "-----END"; is >> s) r += s;
	return r;
}

static unsigned char c2b(char c)
{//char to 6bit
	if('A' <= c && c <= 'Z') return c - 'A';
	if('a' <= c) return c - 'a' + 26;
	if('0' <= c) return c - '0' + 52;
	return c == '+' ? 62 : 63;
}

vector<unsigned char> base64_decode(string s)
{
	int padding = 0;
	for(int i=0; s[s.size()-1-i] == '='; i++) padding++;
	unsigned char bit[4];
	vector<unsigned char> v;
	for(int i=0; i<s.size(); i+=4) {
		for(int j=0; j<4; j++) bit[j] = c2b(s[i+j]);
		v.push_back(bit[0] << 2 | bit[1] >> 4);
		v.push_back(bit[1] << 4 | bit[2] >> 2);
		v.push_back(bit[2] << 6 | bit[3]);
	}
	for(int i=0; i<padding; i++) v.pop_back();
	return v;
}

int main(int ac, char **av) {
	ifstream f(av[1]); int r = 0;
	for(string s; (s = get_certificate_core(f)) != "";) r += base64_decode(s).size();
	cout << "static const int certificate_sz = " << r << ';';
	return 0;
}

