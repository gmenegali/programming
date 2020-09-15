#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

void solution(vector<int> &v){
	ll last = 0;
	int n = (int) v.size();

	cout << 1 << " " << n << endl;
	for(int i=0; i < (int) v.size(); i++){
		cout << (ll) v[i] * (-n) << " ";
		if(i == (int)v.size()-1){
			last = (ll) v[i] + (ll) v[i] * (-n);
		}
	}
	if(n > 1){
		cout << endl << 1 << " " << n-1 << endl;
		for(int i=0; i < (int) v.size()-1; i++){
			cout << (ll) v[i] * (n-1) << " ";
		}
	} else {
		cout << endl << 1 << " " << 1 << endl;
		cout << 0;
	}

	cout << endl << n << " " << n << endl;
	cout << -last << endl;
}


int main(){
	int n, x;
	vector<int> testCase;
	
	cin >> n;
	while(n){
		cin >> x;
		testCase.push_back(x);
		n--;
	}
	solution(testCase);

	return 0;
}