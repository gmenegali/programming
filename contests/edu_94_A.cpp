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

void solution(int n, string s){
	vector<vector<int>> matrix (n, vector<int>(n, 0));
	string result = "";

	for(int i=0; i<n; i++){
		int k=0;
		for(int j=i; j<i+n; j++){
			if(s[j] == '1')
				matrix[i][k] = 1;
			else
				matrix[i][k] = 0;
			k++;
		}
	}

	// for(int i=0; i<n; i++){
	// 	printVec(matrix[i]);
	// }
	// cout << endl << endl;

	vector<int> ones;
	vector<int> zeros;
	set<int> used;

	for(int j=0; j<n; j++){
		for(int i=0; i<n; i++){
			if(used.find(i) == used.end()){
				if(matrix[i][j] == 1)
					ones.push_back(i);
				else
					zeros.push_back(i);
			}
		}

		if((int) ones.size() > 0 and (int) ones.size() > (int) zeros.size()){
			for(int m=0; m<(int) ones.size(); m++){
				used.emplace(ones[m]);
			}
			result.push_back('1');
		}
		else{
			if((int) zeros.size() > 0){
				for(int m=0; m<(int) zeros.size(); m++){
					used.emplace(zeros[m]);
				}
				result.push_back('0');
			}
		}

		// printVec(ones);
		// printVec(zeros);


		ones.clear();
		zeros.clear();
		if((int) used.size() == n)
			break;
	}

	while((int) result.size() < n){
		result.push_back('0');
	}
	// cout << endl << endl << endl;
	cout << result << endl;

}

int main(){
	int t, n;
	string s;
	
	cin >> t;
	while(t){
		cin >> n >> s;
		solution(n,s);
		t--;
	}

	return 0;
}