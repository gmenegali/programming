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
	vector<int> locked;
	
	cin >> t;
	while(t){
		cin >> n;
		
		for(int i=0; i<n; i++){
			cin >> x;
			testCase.push_back(x);
		}

		for(int i=0; i<n; i++){
			cin >> x;
			locked.push_back(x);
		}

		//Sorting
		for(int i=0; i<n; i++){
			if(locked[i] != 1){
				for(int j=i+1; j<n; j++){
					if(locked[j] != 1 and testCase[j] > testCase[i]){
						swap(testCase[i], testCase[j]);
					}
				}
			}
		}
		printVec(testCase);
		// printVec(locked);
		// cout << endl;

		testCase.clear();
		locked.clear();
		t--;
	}


	return 0;
}