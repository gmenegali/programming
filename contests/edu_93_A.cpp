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

void solution(vector<int> &v){
	int length = (int) v.size();
	int first = v[0];
	int last = v[length-1];

	int candidate1 = v[1];
	int candidate2 = v[length-2];

	if(first + candidate1 <= last){
		cout << "1 " << "2 " << length << endl;
		return;
	}

	if(first + candidate2 <= last){
		cout << "1 " << length-1 << " " << length << endl;
		return;
	}

	cout << "-1" << endl;
}

int main(){
	int t, n, x;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> n;
		while(n){
			cin >> x;
			testCase.push_back(x);
			n--;
		}
		solution(testCase);
		testCase.clear();
		t--;
	}


	return 0;
}