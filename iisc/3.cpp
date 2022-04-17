#include <bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &a) {
	for (int i = 0; i < a.size(); i++) {
		int key = a[i];
		//  may not be the correct place for it
		int j = i - 1;
		while (key < a[j] && j >= 0) {
			// key is smaller
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = key;
	}
}

// similar to median of running stream

void insertion_pass(vector<int> &a) {
	// place the last element at correct place
	int key = a[a.size() - 1];
	int i = a.size() - 1;
	int j = i - 1;
	while (key < a[j] && j >= 0 ) {
		a[j + 1] = a[j];
		j = j - 1;
	}
	a[j + 1] = key;
}


int main() {
	// take input till it ends
	int n;
	vector<int> a;
	// store the numbers as a max heap
	// in C++ priority_queue is by default a max heap
	priority_queue<int> small_heap;
	// store numbers as a min heap
	priority_queue<int, vector<int>, greater<int>> large_heap;
	while (cin >> n) {
		small_heap.push(n);
		// if one of them has more elements, their size is not approx same
		// take out from one and put in another
		if ((small_heap.top() > large_heap.top()) || (small_heap.size() - large_heap.size() > 1)) {
			large_heap.push(small_heap.top());
			small_heap.pop();
		}
		else if (large_heap.size() - small_heap.size() > 1) {
			small_heap.push(large_heap.top());
			large_heap.pop();
		}

	}
	double ans;
	if (large_heap.size() > small_heap.size()) {
		ans = (double)large_heap.top();
	}
	if (large_heap.size() < small_heap.size()) {
		ans = (double)small_heap.top();
	}
	else {
		ans = (double) ((small_heap.top() + large_heap.top()) / 2);
	}
	cout << ans << endl;
}