#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

void printVec(vector<char> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

int main(){
	int t, n, m;
	char x;
	vector<char> lastRow;
	vector<char> lastCol;
	
	cin >> t;
	while(t){
		cin >> n >> m;
		lastCol.resize(n);
		lastRow.resize(m);

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> x;
				if(i==n-1){//Last row
					lastRow[j] = x;
				}
				if(j==m-1){//Last column
					lastCol[i] = x;
				}
			}
		}

		int result = 0;
		for(int i=0; i<n; i++){
			if(lastCol[i] != 'D')
				result++;
		}

		for(int i=0; i<m; i++){
			if(lastRow[i] != 'R')
				result++;
		}

		cout << result-2 << endl;
		lastCol.clear();
		lastRow.clear();

		t--;
	}


	return 0;
}