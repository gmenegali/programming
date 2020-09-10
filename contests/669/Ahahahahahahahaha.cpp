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
	vector<int> ans;
	
	cin >> t;
	while(t){
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> x;
			testCase.push_back(x);
		}

		int zeros = 0, ones = 0;
		for(int i=0; i<n; i++){
			zeros = 0;
			ones = 0;
			if(i+3<n){
				if(testCase[i] == 1)
					ones++;
				else
					zeros++;
				if(testCase[i+1] == 1)
					ones++;
				else
					zeros++;
				if(testCase[i+2] == 1)
					ones++;
				else
					zeros++;
				if(testCase[i+3] == 1)
					ones++;
				else
					zeros++;
				if(zeros >= ones){
					ans.push_back(0);
					ans.push_back(0);
				}
				else{
					ans.push_back(1);
					ans.push_back(1);
				}
				i+=3;
			}
			else{
				if(testCase[i] == 1 and testCase[i+1] == 1){
					ans.push_back(1);
					ans.push_back(1);
				}
				else{
					ans.push_back(0);
				}
				i++;
			}
		}

		cout << (int) ans.size() << endl;
		printVec(ans);
		ans.clear();
		testCase.clear();
		t--;
	}


	return 0;
}