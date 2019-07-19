#include<regex>
#include<iostream>
using namespace std;

int main(int ac, char **av)
{
	regex e{string{"https://image.+"} + av[1] + ".+\\.jpg"};
	smatch m; string s;
	while(getline(cin, s)) { 
		while(regex_search(s, m, e)) { 
			cout << m[0] << endl;
			s = m.suffix();
		}
	}
}

