#include <bits/stdc++.h>
using namespace std;

int kadane(vector<int> arr, int n) {

}

/**
 * [1,2,-5,6,7]
 */


int main() {
	// the array can obviously contain negative values, otherwise the entire array is tha ans
	vector<int> arr = {1, 2, 3, -2, 5};
	int n = arr.size();

	cout << kadane(arr, n) << endl;
}