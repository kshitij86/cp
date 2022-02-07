#include <bits/stdc++.h>
using namespace std;

int main(){
	long long n, presum = 0, tsum = 0;
	cin >> n;
	for(int i=0; i<n-1; i++){
		int x; 
		cin >> x; 
		tsum += x; 
	}
	for(int i=1; i<=n; i++){
		presum += i;
	}

	cout << presum - tsum << endl; 
	return 0;
}