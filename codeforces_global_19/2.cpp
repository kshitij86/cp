#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll mex(vector<ll> &a) {
	sort(a.begin(), a.end());
	ll mex = 1;
	for (auto& e : a) {
		if (e == mex) {
			mex++;
		}
	}
	return mex;
}

int outer_func(int index, vector<ll> &arr, vectr<ll> &ds, int n) {
	if (index == n - 1) {
		//picked up the last element
		//now time to find the cost of this subsequence
		value += inner_func(ds);
	}

	ds.push_back(arr[index]);
	outer_func(index + 1, arr, ds, n);
	ds.pop_back(arr[index]);
	outer_func(index + 1; arr, ds, n);

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
#endif
	int t, i, j, k, l, m, n;
	cin >> t;

	while (t--) {
		vector<ll> arr
		vector<ll> ds;
		fill(ds.begin(), ds.end(), 0);

		cin >> n;
		for (int i = 0 ; i < n; i++) {
			int x;
			cin >> x;
			arr.push_back(x);
		}
		int value = 0;
		//outer func calls for each subsequence
		//it will call inner func and find out the best partition for that sub-array
		outer_func();
	}

}