#include <algorithm>
#include <vector>
#include <iostream>
#include <climits>
using namespace std;

int majority(int n, vector<int> arr) {
	int ma =  *max_element(arr.begin(), arr.end());
	vector<int> freq(ma + 1, 0);
	for (int i = 0; i < n; i++) {
		freq[arr[i]]++;
	}
	for (int i = 0; i < ma + 1; i++) {
		if (freq[i] > n / 2) {
			return i;
		}
	}
	return INT_MIN;
}

int main() {

	vector<int> a1 = {3, 2, 3};
	vector<int> a2 = {2, 2, 1, 1, 1, 2, 2};
	vector<int> a3 = {2, 3, 1, 1, 1, 2, 2};
	cout << majority(a1.size(), a1) << endl;
	cout << majority(a2.size(), a2) << endl;
	cout << majority(a3.size(), a3) << endl;

}