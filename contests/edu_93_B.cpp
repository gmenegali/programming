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

int solution(string s){
	vector<int> seq;
	int counter = 0, result = 0;

	for(int i=0; i < (int) s.size(); i++){
		if(s[i] == '1'){
			counter++;
			if(i == (int) s.size()-1){
				seq.push_back(counter);
			}
		}
		else {
			if(counter != 0){
				seq.push_back(counter);
				counter = 0;
			}
		}
	}
	sort(seq.begin(), seq.end(), greater<int>());
	
	for(int i=0; i<(int)seq.size(); i+=2){
		result += seq[i];
	}


	return result;
}

int main(){
	int t;
	string s;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> s;
		cout << solution(s) << endl;
		t--;
	}


	return 0;
}