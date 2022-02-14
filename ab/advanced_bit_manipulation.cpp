#include <bits/stdc++.h>
using namespace std;

int find_single_number_in_double_repeating_array(vector<int> &arr) {
	//find the number that occur only once in array where every other number repeats twice
	//this logic works because xor of single number with itself is zero
	int res = 0;
	for (auto it : arr) {
		res = it ^ res;
	}
	return res;
}

vector<int> find_two_single_numbers_in_double_repeating_array(vector<int> &arr) {
	vector<int> left, right;
	//algo to find such numbers
	/*	1. after performing XOR of aal numbers we will have a^b left as all duplicates will get cancelled
		2. now we can find all numbers in the array the have their 0th bit same as a^b, put them all in one array
		3. we can put all other in another array
		4. now XOR a^b with all numbers in one array will give of the numbers and in another array will give second number
	*/

	int x;
	for (auto it : arr) {
		x ^= it;
		int mask = 1;
		if (it & mask == 0)
			left.push_back(it);
		else
			right.push_back(it);
	}
	//now x has a^b
	int a = x, b = x;
	for (auto it : left) {
		a ^= it;
	}
	for (auto it : right) {
		b ^= it;
	}

	left.clear();
	left.push_back(a);
	left.push_back(b);

	return left;

}

int main() {
	vector<int> A{1, 1, 2};
	vector<int> B{5, 5 , 3, 3, 1, 2};
	vector<int> rec;

	cout << find_single_number_in_double_repeating_array(A) << endl; //expected: 2
	rec = find_two_single_numbers_in_double_repeating_array(B);

	for (auto it : rec) {
		cout << it << " ";
	} cout << endl;
}