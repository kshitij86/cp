#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll longest_increasing_subsequence(vector<ll> arr){

    vector<ll> dp(arr.size(), 0);
    dp[0] = 1; // the longest subsequence until that point is that element itself
    /**
     * if (arr[i] >arr[i-1])
     *   dp[i] = dp[i-1] + 1
     * else 
     *   dp[i] = dp[i-1]
     * 
     */
    for(ll i=1; i<arr.size(); i++){
        if(arr[i-1] < arr[i]){
            //the subsequence can increase
            dp[i] = dp[i-1] + 1;
        } else {
            dp[i] = dp[i-1];
        }
    }

    return dp[arr.size()-1];
}


int main(){
    vector<ll> arr = {1,1,2,3,8,7,6};
    cout << longest_increasing_subsequence(arr) << endl;

}