#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// https://www.codechef.com/problems/CNTPEAK

void gen_all(ll index, ll n, vector<ll> ds, set<vector<ll>> &res) {
	if (index == n) {
		res.insert(ds);
		return;
	}

	for (int i = 0; i < n; i++) {
		// place 0
		ds.push_back(0);
		gen_all(index + 1, n, ds, res);
		ds.pop_back();

		// place 1
		ds.push_back(1);
		gen_all(index + 1, n, ds, res);
		ds.pop_back();

		// place 2
		ds.push_back(2);
		gen_all(index + 1, n, ds, res);
		ds.pop_back();
	}
}

void brute(ll n) {
	// slow brute force solution - TLE
	set<vector<ll>> res;
	vector<ll> ds;
	gen_all(0, n, ds, res);

	ll cnt = 0;
	for (auto itr : res) {
		for (int i = 1; i < itr.size() - 1; i++) {
			if ((itr[i - 1] > itr[i]) && (itr[i] < itr[i + 1])) {
				cnt++;
			} else if ((itr[i - 1] < itr[i]) && (itr[i] > itr[i + 1])) {
				cnt++;
			}
		}
	}
	cout << cnt << endl;
}

// since extrema is defined using three values, only some cases are possible
/*
	[2,1,2]
	[2,0,2]
	[1,0,1]
	[0,1,0]
	[0,2,0]
	[0,2,1]
	[1,2,1]
	[1,0,2]
	[2,0,1]
	[1,2,0]

	this can be solved using permutation and combo as well

	ans = (10) * (n-2) * pow(3, n-3)

	n-2 -> number of ways to pick three positions
	10 -> number of peak combinations
	pow(3, n-3) -> number of ways to place elements in other positions
*/

void fast(ll n) {
	ll ans = 0;
	if (n > 2)
		ans = (10) * (n - 2) * (pow(3, n - 3));
	cout <<  ans << endl;
}


int main() {
	ll t, n;
	cin >> t;
	while (t--) {
		cin >> n;
		fast(n);
	}

}