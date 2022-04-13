//https://takeuforward.org/data-structure/sort-an-array-of-0s-1s-and-2s/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> arr) {
	for (auto i : arr) {
		cout << i << " ";
	}
}

void solve(vector<int> arr) {
	// naive 2 pass approach using count sort as maximum number is 2
	// question demands for single pass O(N) solution
	// need to strive
	vector<int> freq(3, 0);
	for (int i = 0; i < arr.size(); i++) {
		freq[arr[i]]++;
	}

	for (int i = 1; i < 3; i++) {
		freq[i] = freq[i - 1] + freq[i];
	}

	vector<int> output(arr.size());
	for (int i = arr.size() - 1; i >= 0; i--) {
		output[--freq[arr[i]]] = arr[i];
	}

	print(output);
}


void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void strive(vector<int> arr) {
	/**
	 * dutch national flag algorithm:
	 *
	 * O(N) single pass algo
	 *
	 * take three pointers -  low, mid and high
	 *
	 * the algorithm works such that -
	 * 1. everything to the left of low is zero
	 * 2. everything from mid to high is 1
	 * 3. every element to the right of high is 2
	 *
	 * 1. move mid pointer while it does not cross high
	 *  if arr[mid] == 0
	 * 		swap(arr[mid], arr[low])
	 * 		mid++
	 *  	low++
	 *	if arr[mid] == 1
	 * 		mid++
	 *  if and arr[mid] == 2
	 * 		swap(arr[high], arr[mid])
	 * 		high--
	 */

	int low = 0, mid = 0, high = arr.size() - 1;
	while (mid <= high) {
		if (arr[mid] == 0) {
			swap(&arr[mid], &arr[low]);
			low++;
			mid++;
		}
		if (arr[mid] == 1) {
			mid++;
		}
		if (arr[mid] == 2) {
			swap(&arr[mid], &arr[high]);
			high--;
		}
	}

	print(arr);
}

int main() {
	vector<int> arr = {2, 0, 2, 1, 1, 0, 0, 1, 2, 0, 0, 1, 2, 1,};

	strive(arr);
}