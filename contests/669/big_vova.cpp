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

int gcd(int a, int b){
	if(a % b != 0){
		return gcd(b, a % b);
	}
	else return b;
}

int main(){
	int t, n, x, maximum;
	vector<int> testCase;
	vector<int> ans;
	
	cin >> t;
	while(t){
		cin >> n;
		maximum = INT_MIN;
		for(int i=0; i<n; i++){
			cin >> x;
			maximum = max(maximum, x);
			testCase.push_back(x);
		}

		int current_gcd = maximum;
		while((int) ans.size() != n){
			int max_gcd = 1, target_index = -1; 
			for(int i=0; i<(int) testCase.size(); i++){
				if(gcd(current_gcd, testCase[i]) > max_gcd){					 
					max_gcd = gcd(current_gcd, testCase[i]);
					target_index = i;
				}

				if(gcd(current_gcd, testCase[i]) == max_gcd){
					if(target_index == -1){
						target_index = i;
					} else {
						if(testCase[i] > testCase[target_index]){
							target_index = i;
						}
					}
				}


			}
			current_gcd = max_gcd;
			ans.push_back(testCase[target_index]);
			testCase.erase(testCase.begin()+target_index);
		}

		printVec(ans);

		testCase.clear();
		ans.clear();
		t--;
	}

	return 0;
}