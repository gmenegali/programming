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

int solution(int a, int k){
	if(a <= k){
		return abs(k-a);
	} else{
		if(a % 2 == 0){
			if(k % 2 == 0){
				return 0;
			} else return 1;
		} else {
			if(k % 2 != 0){
				return 0;
			} else return 1;
		}
	}
}

int main(){
	int t, n, k;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> n >> k;
		cout << solution(n, k) << endl;
		t--;
	}


	return 0;
}