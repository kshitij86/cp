#include<bits/stdc++.h>
using namespace std;

void n_queens(int index, int queens, vector<int> &solution){
    if(index == queens){
        return;
    }
    for(int i=0; i<queens; i++){
       if(solution[i] == -1){
            // a queen has been placed 
            solution[index] = i;
            n_queens(index+1, queens, solution);
       }
    }

    if(solution[index] == -1){
        // queen could not be placed
        solution[index-1] = -1;
        n_queens(index-1, queens, solution);
    }
}

/**
 * solution = [-1, -1, -1, -1] 
 * 
 * 
 */

int main(){
    // 4x4 chess board, 4 queens to be placed
    int queens = 4;

    vector<int> solution(queens, -1);
    n_queens(0, queens, solution);
    for(auto itr: solution){
        cout << itr << " ";
    }
    cout << endl;
}