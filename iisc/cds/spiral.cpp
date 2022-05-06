#include <iostream>
#include <vector>
using namespace std;

/*
  Needs fixing, last element is printed twice
*/


void spiral_print(int start_row, int start_col, vector<vector<int>> mat, int max_row, int max_col){
  // recursive function to print it in sprial order
  // print the matrix layer by layer
  // then call the funtion for the next layer
  if(start_row >= max_row || start_col >= max_col){
    return;
  }

  // loop to print upper row of layer
  for(int p=start_col; p<max_col; p++){
    cout << mat[start_row][p] << endl;
  }
  // right column/last column
  // column does not change
  for(int p=start_row+1; p<max_row; p++){
    cout << mat[p][max_col-1] << endl;
  }

  // last row of the layer
  // start at second last column
  for(int p=max_col-2; p>=0; p--){
    cout << mat[max_row-1][p] << endl;
  }

  // first column of the layer/leading column
  // change the row
  for(int p=max_row-2;p>start_row;p--){
    cout << mat[p][start_col] << endl;
  }

  spiral_print(start_row+1, start_col+1, mat, max_row-1, max_col-1);

}

void print_matrix(vector<vector<int>> mat){
  // just print the matrix
  int n = mat.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout << mat[i][j] << " ";
    }
    cout << endl;
  }
}

int main(){
    // given nxn matrix, print its spiral traversal in clockwise direction
    int n;
    cin >> n;
    // initialized to zeroes
    vector<vector<int>> mat(n, vector<int> (n));
    for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
        int x;
        cin >> x;
        mat[i][j] = x;
      }
    }

    spiral_print(0, 0, mat, n, n);
}
