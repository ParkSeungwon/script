#include<set>
#include<iostream>
using namespace std;

set<int> prime;
bool is_prime(int k) {
	for(int i : prime) if(k % i == 0) return false;
	return true;
}

int main(int ac, char **av)
{//goldbach conjecture
	int k = atoi(av[1]);
	for(int i=2; i<k; i++) if(is_prime(i)) prime.insert(i);
//	for(auto it = prime.begin(); *it <= k / 2; it++)
//		if(prime.find(k - *it) != prime.end())
//			cout << k << " = " << *it << " + " << k - *it << endl;
}
	

