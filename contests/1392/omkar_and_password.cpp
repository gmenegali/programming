#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> &v){
	int first_value = v[0];
	for(int i=1; i < (int) v.size(); i++){
		if(first_value != v[i])
			return 1;
	}

	return (int) v.size();
}

int main(){
	int n, m, x;

	vector<int> testCase;

	cin >> n;
	while(n){
		cin >> m;
		while(m){
			cin >> x;
			testCase.push_back(x);
			m--;
		}
		cout << solution(testCase) << endl;
		testCase.clear();
		n--;
	}
	


	return 0;
}