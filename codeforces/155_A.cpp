#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin >> n;
	
	vector<int> arr;
	for(int i=0; i<n; i++){
		int x;
		cin >> x;
		arr.push_back(x);
	}

	int ama = 0;
	for(int i=1; i<n; i++){
		int big = 0, small = 0;
		for(int j=i; j>=0; j--){
			if(arr[j] > arr[i])
				small++;
			if(arr[j] < arr[i])
				big++;
		}
	
		if((big == i) || (small == i))
			ama++;
	}
	
	cout << ama << endl;
}
