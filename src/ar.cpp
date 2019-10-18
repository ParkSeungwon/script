#include<iostream>
using namespace std;

int ar[10][10];

void init(int (*p)[10]) {
	for(int i=0; i<10; i++) for(int j=0; j<10; j++) p[i][j] = 0;
}
void show() {
	for(int i=0; i<10; i++) for(int j=0; j<10; j++) cout << ar[i][j];
}
int main() {
	init(ar);
	show();
}

