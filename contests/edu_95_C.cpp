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
	int t, n, x, skip;
	vector<int> testCase;
	
	cin >> t;
	while(t){
		cin >> n;
		
		for(int i=0; i<n; i++){
			cin >> x;
			testCase.push_back(x);
		}

		string turn = "he";
		skip = 0;
		for(int i=0; i<n; i++){
			if(turn == "he"){
				if(testCase[i] == 1){
					skip++;
				}
				if(i<n-1 and testCase[i+1] == 0){
					if(i+1<n-1){
						if(testCase[i+2] != 0)
							i++;
					}
					else{
						i++;
					}
				}
				turn = "me";
			}

			else if(turn == "me"){
				if(i<n-1 and testCase[i+1] == 1){
					i++;
				}
				turn = "he";
			}
		}
		

		cout << skip << endl;
		testCase.clear();
		t--;
	}


	return 0;
}