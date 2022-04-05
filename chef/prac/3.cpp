#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

//https://www.codechef.com/LP2TO305/problems/CHFNA

// simple modification of XOR property
// if x and y are one, then a should be one
// if x and y are zero, then a should be zero


int main(){
	int t, x, y;
	cin >> t;
	while(t--){
		cin >> x >> y;
		cout << (int)(x ^ y) << endl;
	}
}