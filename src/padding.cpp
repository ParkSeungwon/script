#include<iostream>
using namespace std;
#pragma pack(2)
struct S1 {
	char c;
	int k;
};
#pragma pack(1)
struct S2 {
	char c;
	int k;
};
#pragma pack()
struct S3 {
	char c;
	int k;
};
int main()
{
	cout << sizeof(S1) << endl;
	cout << sizeof(S2) << endl;
	cout << sizeof(S3) << endl;
}

