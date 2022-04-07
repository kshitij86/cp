#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//https://www.codechef.com/LP2TO305/problems/ENGXOR
/*
	very large input to brute force will always give TLE
	better approach is to check the parity of the input numbers and use that to make decision
	so if the number p is odd, then the parity of actual numbers gets flipped
	else it remains the same

	c -> used to store the count of even parity and odd parity numbers

*/


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll t, n, q, x;
	cin >> t;
	while (t--) {
		cin >> n >> q;
		ll c[2] {0};
		for (int i = 0; i < n; i++) {
			cin >> x;
			c[__builtin_popcount(x) % 2]++;
		}

		while (q--) {
			cin >> x;
			ll z = __builtin_popcount(x);
			if (z % 2 == 0) {
				cout << c[0] << " " <<  c[1] << endl;
			} else {
				cout << c[1] << " " <<  c[0] << endl;
			}
		}
	}
}
