#include <bits/stdc++.h>
using namespace std;

void print_board(int board[9][9]){
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}

bool isValid(int board[9][9], int row, int col, int k){
	//k -> number to check at that place
	for(int i=0; i<9; i++){
		if(board[i][col] == k){
			return false;
		}
		if(board[row][i] == k){
			return false;
		}
		//check in same square
		if(board[(3 * (row/3)) + i/3][(3 * (col/3)) + i%3] == k){
			return false;
		}
	}
	return true;
}


bool solve(int board[9][9]){
	//outer loop searches for empty space
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			//if space is empty
			if(board[i][j] == 0){
				for(int k=1; k<=9; k++){
					if(isValid(board, i, j, k)){
						board[i][j] = k;
						
						if(solve(board) == true){
							//if this recursive call was able to give me a solution
							return true;
						} else {
							//else vacate this place, cant place this number here
							board[i][j] = 0;
						}
					}
				}
				//tried to place all numbers at this place, could not get a solution from this branch
				return false;
			}
		}
	}
	//all spaces have been filled, outer loop found no empty space
	return true;
}


int main(){
	int board[9][9];
	for(int i=0; i<9; i++){
		for(int j=0; j<9; j++){
			board[i][j] = 0;
		}
	}

	solve(board);
	print_board(board);
}