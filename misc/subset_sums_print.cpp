// https://www.youtube.com/watch?v=rYkfBRtMJr8&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=10

#include <bits/stdc++.h>
using namespace std;

//print all the sums of the subsets in increasing order
void subset_sums(int index, int *arr, int n, vector<int> &ds, vector<int> &store_sums, int sum) {
	if (index == n) {
		//store the current sum in the array
		store_sums.push_back(sum);
		return;
	}

	//pick this element and see what the subset sum is
	ds.push_back(arr[index]);
	subset_sums(index + 1, arr, n, ds, store_sums, sum + arr[index]);
	//discard this element and see what the subset sum is
	ds.pop_back();
	subset_sums(index + 1, arr, n, ds, store_sums, sum);
}


int main() {
	int arr[] = {3, 1, 2};
	int n = sizeof(arr) / sizeof(int);
	int sum = 0;
	vector<int> store_sums, ds;

	subset_sums(0, arr, n, ds, store_sums, sum);

	sort(store_sums.begin(), store_sums.end());
	for (auto it : store_sums) {
		cout << it << " ";
	}
	cout << endl;
}