#include <bits/stdc++.h>
#define MAX_LEN 10e4
using namespace std;

bool isSorted(vector<int> &arr) {
	for (int i = 0; i < arr.size() - 1; i++) {
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}

bool doesPeakExist(vector<int> &arr) {
	for (int i = 1; i < arr.size() - 1; i++) {
		if (arr[i - 1] < arr[i] && arr[i] > arr[i + 1])
			return true;
	}
	return false;
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
#endif
	int t, i, j, k, l, m, n;
	cin >> t;
	while (t--) {
		vector<int> arr;
		cin >> n;
		for (int i = 0 ; i < n; i++) {
			int x;
			cin >> x;
			arr.push_back(x);
		}

		if (isSorted(arr)) {
			cout << "NO" << endl;
		}
		else {
			cout << "YES" << endl;
		}
	}
}