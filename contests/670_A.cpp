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
		int maximum = INT_MIN;
		for(int i=0; i<n; i++){
			cin >> x;
			maximum = max(maximum, x);
			testCase.push_back(x);
		}

		vector<int> counter(maximum+1, 0);
		for(int i=0; i<n; i++){
			counter[testCase[i]] +=1;
		}

		int i = 0;
		int j = 0;
		while(i <= maximum and counter[i] >= 2){
			i++;
			j++;
		}

		while(i <= maximum and counter[i] >= 1){
			i++;
		}

		cout << i+j << endl;

		testCase.clear();
		counter.clear();
		t--;
	}


	return 0;
}