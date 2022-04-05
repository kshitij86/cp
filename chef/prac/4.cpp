#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//https://www.codechef.com/LP2TO305/problems/XORORED

//very simple, find the number with most number of set bits

int count_set(int x){
	int r = 0;
	while(x){
		if(x&1 == 1){
			r++;
		}
		x/=2;
	}
	return r;
}

int main(){
	ll t;
	cin >> t;
	while(t--){
		int n;
		cin >> n;
		int d;
		ll a[100];
		ll ma = INT_MIN;
		for(int i=0; i<n; i++){
			cin >> a[i];
			if(ma < count_set(a[i])){
				d = a[i];
				ma = count_set(a[i]);
			}
		}

		int u = 0;
		for(int i=0; i<n; i++){
			u |= (a[i] ^ d);
		}
		cout << d << " " << u << endl;
	}

}