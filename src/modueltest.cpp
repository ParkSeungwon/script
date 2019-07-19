#include<fstream>
#include<iostream>
using namespace std;

int main(int ac, char **av)
{
	ifstream f("/dev/memory");
	for(char i=0, c; i<atoi(av[1]); i++) f >> c, cout << c;
}

