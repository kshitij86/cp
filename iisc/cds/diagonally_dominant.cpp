#include <iostream>
#include <vector>
using namespace std;

int main(){
  int n;
  cin >> n;

  int k = 0, is_dominant = 1;
  for(int i=0; i<n; i++){
    float rest_sum = 0.0, diag_sum;
    for(int j=0; j<n; j++){
      float x;
      cin >> x;
      if(i!=j){
        rest_sum += x;
      } else {
        diag_sum = x;
      }
    }
    k++;
    // after this row is over
    if(diag_sum - rest_sum > 0.0){
      // the diagonal element is greater
    } else {
      is_dominant = 0;
    }
  }

  is_dominant ? cout << "True" : cout << "False";
  cout << endl;

}
