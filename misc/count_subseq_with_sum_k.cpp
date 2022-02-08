#include <bits/stdc++.h>
using namespace std;

int cnt = 0;

void count_subseq_with_sum_k(int ind, int arr[], int n, int k, int sum) {
	if (ind == n) {
		if (sum == k)
			cnt ++;
		return;
	}

	//take this element
	count_subseq_with_sum_k(ind + 1, arr, n, k, sum + arr[ind]);
	count_subseq_with_sum_k(ind + 1, arr, n, k, sum);
}

int better_count_subseq_with_sum_k(int ind, int sum, int k, int arr[], int n) {
	//a better functionwithout the use of global variables

	if (ind == n) {
		if (sum == k)
			return 1;
		else return 0;
	}

	//here we take the two branches of recursion and add their result
	int l = better_count_subseq_with_sum_k(ind + 1, sum + arr[ind], k, arr, n); // the take branch where element is taken
	int r = better_count_subseq_with_sum_k(ind + 1, sum, k, arr, n); // the don't take branch where element is not taken

	return l + r;
}

int main() {
	// return the count of subequences with a sum of k in given array
	// similar to printing all subsequences except
	/*
		1. no need to maintain a ds as we don't need to print the subseq
		2.whenever sum hits the k value, increment count
		3. count is initialized to zero
	*/

	int arr[] = {1, 2, 1};
	int k = 3;
	int n = sizeof(arr) / sizeof(int);

	// count_subseq_with_sum_k(0, arr, n, k, 0);
	cout <<	better_count_subseq_with_sum_k(0, 0, k, arr, n) << endl;

}