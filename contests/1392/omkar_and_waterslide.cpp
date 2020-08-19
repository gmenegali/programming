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

unsigned long long int solution(vector<int> &v){
	unsigned long long int result = 0;
	int step = v[0], previous;

	for(int i=1; i < (int) v.size(); i++){
		if(step <= v[i]){
			step = v[i];
		} else{
			previous = step;
			while(i < (int) v.size() and step > v[i]){
				if(previous > v[i]) {
					result += previous - v[i];
				}
				previous = v[i];
				i++;
			}
			i--;
		}
	}

	return result;
}

int main(){
	int t,n,x;
	vector<int> testCase;

	cin >> t;
	while(t){
		cin >> n;
		while(n){
			cin >> x;
			testCase.push_back(x);
			n--;
		}
		cout << solution(testCase) << endl;
		testCase.clear();
		// printVec(testCase);
		t--;
	}
	return 0;
}