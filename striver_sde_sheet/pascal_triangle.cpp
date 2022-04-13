//https://takeuforward.org/data-structure/program-to-generate-pascals-triangle/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<vector<int>> matrix) {
	for (auto i : matrix) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

void solve(int n) {
	// same as strive
	vector<vector<int>> triangle;

	for (int i = 0; i < n; i++) {
		vector<int> new_vec(i + 1);
		// set the first and last indices to 1
		new_vec[0] = 1;
		new_vec[(new_vec.size()) - 1] = 1;
		triangle.push_back(new_vec);
	}
	// compute the value of the triangle
	// can start at third row because above that computation is not required
	for (int i = 2; i < n; i++) {
		// start at second index as first is one
		// end at second last as last is one
		for (int j = 1; j < i; j++) {
			triangle[i][j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
		}
	}
	print(triangle);
}

int main() {
	int n = 14;

	solve(n);
}