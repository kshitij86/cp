#include <bits/stdc++.h>
using namespace std;

void print(int *arr, int n){
	for(int i=0; i<n; i++){
		cout << arr[i] << " ";
	}
}

int main(){
	int k, l, m, n, d;
	cin >> k >> l >> m >> n >> d;
	int nod = 0;
	
	int harmed[d+1];
	memset(harmed, 0, sizeof(harmed));
	for(int i=k; i<=d; i+=k){
		harmed[i] = 1;
	}	
	
	for(int i=l; i<=d; i+=l){
		harmed[i] = 1;
	}	
	
	for(int i=m; i<=d; i+=m){
		harmed[i] = 1;
	}	
	
	for(int i=n; i<=d; i+=n){
		harmed[i] = 1;
	}	
	
	int cnt = 0;
	for(int i=1; i<=d; i++){
		if(harmed[i] == 1)
			cnt++;
	}
	//print(harmed, d);

	cout << cnt << endl;
}
