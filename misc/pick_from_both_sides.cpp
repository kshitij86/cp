#include <bits/stdc++.h>
using namespace std;

void max_B_length(int index, int B, vector<int> &arr, vector<int> &ds, int n, vector<int> &sums, int sum) {
	if (index == n) {
		if (ds.size() == B) {
			sums.push_back(sum);
		}
		return;
	}

	//pick this element
	ds.push_back(arr[index]);
	max_B_length(index + 1, B, arr, ds, n, sums, sum + arr[index]);
	ds.pop_back();
	max_B_length(index + 1, B, arr, ds, n, sums, sum);
}

int main() {
	vector<int> A =  {5, -2, 3 , 1, 2};
	int B = 3;
	int n = A.size();
	vector<int> ds;
	vector<int> sums;

	max_B_length(0, B, A, ds, n, sums, 0);

	cout << *max_element(sums.begin(), sums.end()) << endl;
}