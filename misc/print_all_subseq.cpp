#include <bits/stdc++.h>
using namespace std;

void print_subseq(int ind, int n, int *arr, vector<int> &ds) {
	if (ind == n) {
		for (auto it : ds) {
			cout << it << " ";
		}
		if (ds.size() == 0) {
			cout << "{}";
		}
		cout << endl;
		return;
	}

	print_subseq(ind + 1, n, arr, ds);
	// take this element and call the recursive function
	ds.push_back(arr[ind]);
	print_subseq(ind + 1, n, arr, ds);
	// don't take it and call the recusrsive function
	ds.pop_back();
}

int main() {
	// print all subsequences of integers from 1 to n
	int arr[] = {3, 1};
	int n = sizeof(arr) / sizeof(int);
	vector<int> ds;
	print_subseq(0, n, arr, ds);
}
