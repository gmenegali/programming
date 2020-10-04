#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << ' ';
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
 
		string s = "";
		for(int i=0; i<200; i++){
			s += "a";
		}
		cout << s << endl;
 
		for(int i=0; i<n; i++){
			if(s[testCase[i]] == 'a'){
				s[testCase[i]] = 'b';
			}
			else{
				s[testCase[i]] = 'a';
			}
			cout << s << endl;
		}
 
		testCase.clear();
		t--;
	}
 
 
	return 0;
}