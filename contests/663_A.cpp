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
	int t, n;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> n;
		for(int i=1; i<=n; i++){
			cout << i << " ";
		}
		cout << endl;
		t--;
	}

	return 0;
}