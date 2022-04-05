#include<bits/stdc++.h>
using namespace std;


int main(){
	int n, lo = 0, lc = 0, ro = 0, rc = 0;	
	
	cin >> n;	
	int x, y;
	for(int i=0; i<n; i++){
		cin >> x >> y;
		if(x == 1){
			lo++;
		} else {
			lc++;
		}
		
		
		if(y == 1){
			ro++;
		} else {
			rc++;
		}
	}
	//cout << lo << " " << lc << " " << ro << " " << rc << endl;	

	cout << min(lo, lc) + min(ro, rc) << endl;
	
}
