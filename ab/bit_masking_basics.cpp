#include <bits/stdc++.h>
using namespace std;

int find_ith_bit(int a, int i) {
	int x = 1 << i; //set the bit at the ith position
	x = a & x; //set it the the value that is set in bit i, atmost one bit is set after this operation
	return x >> i; //bring that bit back to starting position and return it
}

int set_ith_bit(int a, int i) {
	//simple bitwise or will set the bit at ith position
	int x = 1 << i; //x has ith bit set
	return a = a | x;
}

int clear_ith_bit(int a, int i) {
	//to clear ith bit we need 0 at i position and all ones at other position
	int x = 1 << i; //x has ith bit set
	x = ~x; //take ones complement so ith bit has 0, all others have 1
	return a = a & x;
}

int no_of_bits_to_change_a_to_b(int a, int b) {
	//sinply find the hamming distance
	int y = a ^ b;
	int cnt = 0;
	/*
		This method will take time equal to number of bits in the digit
		while (y > 0) {
		if (y & 1 == 1)
			cnt++;
		y /= 2;
	}
	 */

	//n & (n-1) approcah to count set bits in number
	//takes time equal to number of set bits, in the worst case all bits are set, rare case
	while (y != 0) {
		cnt ++;
		y &= (y - 1);
	}

	return cnt;
}

int main() {
	unsigned int a = 5;

	cout << find_ith_bit(a, 0) << endl;
	cout << set_ith_bit(a, 1) << endl;
	cout << clear_ith_bit(a, 2) << endl;
	cout << no_of_bits_to_change_a_to_b(6, 7) << endl;
}