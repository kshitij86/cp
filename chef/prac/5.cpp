#include <bits/stdc++.h>
typedef long long ll;
#define MAX_SIZE 200006
using namespace std;

//https://www.codechef.com/LP2TO305/problems/MAXDMGE

/*
	Properties of BITWISE AND:
	(x&y) <= min(x,y) -> as AND gives zero for majority cases (gives one only when both bits are one)

	So for this reason, only arrays of size 2 should be considered
*/

int main() {
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		ll a[MAX_SIZE], ans[MAX_SIZE];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		ans[0] = a[0] & a[1];
		ans[n - 1] = a[n - 2] & a[n - 1];

		for (int i = 1; i < n; i++) {
			ans[i] = max(a[i - 1] & a[i], a[i] & a[i + 1]);
		}

		for (int i = 0; i < n; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
	}
}