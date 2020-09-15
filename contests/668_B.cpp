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
		// printVec(testCase);

		ll credit = 0;
		for(int i=0; i<n; i++){
			if(testCase[i] > 0){
				credit += testCase[i];
			}
			else{
				if(credit > 0){
					if(credit <= abs(testCase[i])){
						testCase[i] += credit;
						credit = 0;
					}
					else{
						credit += testCase[i];
						testCase[i] = 0;
					}
				}
			}
		}
		cout << credit << endl;

		testCase.clear();
		t--;
	}


	return 0;
}