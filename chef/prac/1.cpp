#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

// https://www.codechef.com/LP2TO305/problems/ADDI

int logf(int x){
	int r = 0;
	while(x){
		r++;
		x /= 2;
	}

	return r;
}

int main(){
	// count the number of unset bits
	int t, n;
	cin >> t;
	while(t--){
		cin >> n;
		int x = n;
		int c = 0;
		while(x){
			if(x&1 == 1){
				c++;
			}
			x = x/2;
		}
		cout << abs(logf(n) - c) << endl;
	}
}