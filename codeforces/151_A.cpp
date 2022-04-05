#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, k, l, c, d, p, nl, np;
	cin >> n >> k >> l >> c >> d >> p >> nl >> np;
	int tot_drink = (k*l);
	int tot_lime =  (c*d);
	
	tot_drink /= n;
	p /= np;	

	cout << (min(min(p, tot_lime), tot_drink)/n) << endl;
}
