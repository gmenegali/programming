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

int main(){
	int t, n, x;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x;
			testCase.push_back(x);
		}

		for(int i=n-1; i>=0; i--){
			cout << testCase[i] << " ";
		}
		cout << endl;
		testCase.clear();
		t--;
	}

	return 0;
}