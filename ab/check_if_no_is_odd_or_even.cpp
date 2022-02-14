#include <bits/stdc++.h>
using namespace std;

int main() {
	//number is odd or even can be checked by AND it with one
	//all odd numbers have the 0th bit set

	int n = 5;
	if (n & 1 == 1) {
		cout << "Number is odd\n";
	} else {
		cout << "Number is even\n";
	}
}
