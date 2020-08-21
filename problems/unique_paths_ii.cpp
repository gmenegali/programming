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
			if(ox < tx and matrix[ox+1][oy] != -1)
				count += countPaths(matrix, ox+1, oy, tx, ty);
			if(oy < ty and matrix[ox][oy+1] != -1)
				count += countPaths(matrix, ox, oy+1, tx, ty);
		} else {
			count = matrix[ox][oy];
		}
		
		matrix[ox][oy] = count;
		
		return count;
	}

	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		for(int i=0; i < (int) obstacleGrid.size(); i++){
			for(int j=0; j < (int) obstacleGrid[i].size(); j++){
				if(obstacleGrid[i][j] == 1)
					obstacleGrid[i][j] = -1;
			}
		}
		if(obstacleGrid[0][0] == -1){
			return 0;
		} else{
			return countPaths(obstacleGrid, 0, 0, (int) obstacleGrid.size()-1, (int) obstacleGrid[0].size()-1);
		}
	}

};

int main(){
	Solution s;
	vector<vector<int>> obstacles = {
		{0,0,0,0},
		{0,1,0,0},
		{0,0,0,0},
	};

	cout << s.uniquePathsWithObstacles(obstacles) << endl;
	printMatrix(obstacles);
	return 0;
}