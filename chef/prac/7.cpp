#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// https://www.codechef.com/LP2TO307/problems/LINCHESS

int main() {
	ll t, n, k;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		ll ans = -1;
		for (int i = 0; i < n; i++) {
			ll p;
			cin >> p;

			if (k % p == 0) {
				ans = max(ans, p);
			}
		}
		cout << ans << endl;
	}
}