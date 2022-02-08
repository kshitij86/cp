// https://www.youtube.com/watch?v=eQCS_v3bw0Q&list=PLgUwDviBIf0rGlzIn_7rsaR2FQ5e6ZOL9&index=7

#include <bits/stdc++.h>
using namespace std;

void subseq_k(int ind, int sum, vector<int> &ds, int arr[], int k, int n) {


	if (sum == k) {
		for (auto it : ds) {
			cout << it << " ";
		}
		cout << endl;

		// we are done here so return from this specific call
		return;
	}
	if (ind == n) return;


	//add the element to the data structure and the sum - take it
	ds.push_back(arr[ind]);
	subseq_k(ind + 1, sum + arr[ind], ds, arr, k, n);

	//don't take element and try to make the sum, so the sum value remains same as before
	ds.pop_back();
	subseq_k(ind + 1, sum, ds, arr, k, n);
}

int main() {
	// print all the subsequences in a given array with sum k
	int arr[] = {1, 2, 3, 4};
	int k = 3, n = sizeof(arr) / sizeof(int);
	vector<int> ds;

	// the solutions are {1,1} and {2}
	/*the steps are:
		1. carry an empty data structure to add elements to and a sum variable initialized to zero
		2. add the current element to the sum
		3. if sum equals k  print that subsequence
		each element has two choices either take or not take
	*/
	subseq_k(0, 0, ds, arr, k, n);
}