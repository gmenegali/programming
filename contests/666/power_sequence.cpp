#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
using namespace std;
 
#define ll unsigned long long int

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}
 
int main(){
	int n, x, n_copy;
	ll result1 = 0, result2 = 0;
	vector<int> testCase;
	
	cin >> n;
	n_copy = n;
	while(n){
		cin >> x;
		testCase.push_back(x);
		n--;
	}
	sort(testCase.begin(), testCase.end());
	// printVec(testCase);

	float c_float = pow(testCase[n_copy-1], 1.0/(n_copy-1));
	int c_l, c_h;
	c_l = (int) c_float;
	c_h = (int) c_float+1;
	// cout << c_h << endl;

	for(int i=0; i < (int) testCase.size(); i++){
		result1 += abs(pow(c_l, i) - testCase[i]);
	}

	for(int i=0; i < (int) testCase.size(); i++){
		result2 += abs(pow(c_h, i) - testCase[i]);
		if(result2 > result1)
			break;
	}	
 	
	cout << min(result1, result2) << endl;
 
	return 0;
}