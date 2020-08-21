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

void printMatrix(vector<vector<int>> &m){
	for(int i=0; i < (int) m.size(); i++){
		printVec(m[i]);
	}
}

class Solution {
public:

	int countPaths(vector<vector<int>> &matrix, int ox, int oy, int tx, int ty){
		if(ox == tx and oy == ty){
			return 1;
		} 
		
		int count = 0;

		if(matrix[ox][oy] == 0){
			if(ox < tx)
				count += countPaths(matrix, ox+1, oy, tx, ty);
			if(oy < ty)
				count += countPaths(matrix, ox, oy+1, tx, ty);
		} else {
			count = matrix[ox][oy];
		}
		
		matrix[ox][oy] = count;
		
		return count;
	}

	int uniquePaths(int m, int n) {
		vector<vector<int>> matrix(m, vector<int> (n, 0));
		return countPaths(matrix, 0, 0, m-1, n-1);
	}
};

int main(){
	Solution s;
	cout << s.uniquePaths(40,10);
	return 0;
}