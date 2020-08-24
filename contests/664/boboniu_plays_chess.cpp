#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void solution(vector<vector<int>> &board, int n, int m, int x, int y){
	board[x][y] = 1;
	cout << x+1 << " " << y+1 << endl;

	if(x != 0 and board[x-1][y] == 0){
		solution(board, n, m, x-1, y);
	} 
	else if(x == 0 and board[n-1][y] == 0){
		solution(board, n, m, n-1, y);
	}
	else if(y != 0 and board[x][y-1] == 0){
		solution(board, n, m, x, y-1);
	}
	else if(y == 0 and board[x][m-1] == 0){
		solution(board, n, m, x, m-1);
	}


}

int main(){
	int n, m, x, y;
	vector<int> testCase;
	
	cin >> n >> m >> x >> y;
	vector<vector<int>> board(n, vector<int> (m, 0));
	solution(board, n, m, x-1, y-1);

	// for(int i =0; i < n; i++){
		// printVec(board[i]);
	// }
	
	return 0;
}