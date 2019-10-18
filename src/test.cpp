#include<string>
#include<iostream>
using namespace std;

string s = "This is test";
const char *p = "This is test";
void printc(int i) {
	if(i == s.size()) return;
	printc(i+1);
	cout << s[i];
}

void printc(const char *p) {
	if(!*p) return;
	printc(p+1);
	cout << *p;
}

template<class It> void rev(It begin, It end) {
	char tmp = *begin;
	*begin = *end;
	*end = tmp;
	if(begin+1 < end-1) rev(begin+1, end-1);
}
void reverseString(string &s) {
	rev(s.begin(), s.end()-1);
}

bool is_vowel(char c) {
	for(const char *p = "aeiouAEIOU"; *p; p++) if(*p == c) return true;
	return false;
}
string reverse_vowel(string s) {
	string r;
	for(char c : s) if(is_vowel(c)) r += c;
	reverseString(r);
	int i=0;
	for(char &c : s) if(is_vowel(c)) c = r[i++];
	return s;
}
int main()
{
	printc(0);
	printc(p);
	cout << endl << s << endl;
	reverseString(s);
	cout << s << endl;
	s = "aA";
	cout << reverse_vowel(s) << endl;
}
