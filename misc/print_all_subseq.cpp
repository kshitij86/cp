#include <bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("input1.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif

	vector<int> arr;
	// print all subsequences of integers from 1 to n
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		arr[i] = i + 1;
	}


	for (int i = 0; i < n; i++)
	{
		// outer loop controls size of subsequence
		if (i == 0) {
			cout << "{}" << endl;
			continue;
		}
		for (int j = 0; j < i; i++) {
			cout << arr[j];
		}
		cout << endl;
	}
}