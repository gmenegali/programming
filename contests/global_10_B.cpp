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

vector<int> iteration(vector<int> v){
	int max = INT_MIN;
	for(int i=0; i < (int) v.size(); i++) {
		if(max < v[i]) max = v[i];
	}
	

	for(int i=0; i < (int) v.size(); i++) {
		v[i] = max - v[i];
	}

	return v;
}

void solution(vector<int> &v, unsigned long long int k){
	vector<vector<int>> result;
	result.push_back(iteration(v));
	result.push_back(iteration(result[0]));

	if(k%2 != 0)
		printVec(result[0]);
	else 
		printVec(result[1]);
}

int main(){
	unsigned long long int k;
	int t, n, x;

	vector<int> testCase;

	cin >> t;
	while(t){
		cin >> n >> k;
		while(n){
			cin >> x;
			testCase.push_back(x);
			n--;
		}
		// printVec(testCase);
		solution(testCase, k);
		testCase.clear();
		t--;
	}
	


	return 0;
}