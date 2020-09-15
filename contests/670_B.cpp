#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

#define ll long long int

void printVec(vector<int> &v){
	for(int i=0; i < (int) v.size(); i++){
		cout << v[i] << " ";
	}
	cout << endl;
}

bool abs_sort(int a, int b){
	return abs(a) < abs(b);
}

int main(){
	int t, n, x;
	ll result = 1;
	vector<int> module;
		
	cin >> t;
	while(t){
		cin >> n;
		int positives = 0, negatives = 0, zeros = 0;
		for(int i=0; i<n; i++){
			cin >> x;
			module.push_back(x);
			if(x>0)
				positives++;
			else if(x == 0)
				zeros++;
			else
				negatives++;
		}

		sort(module.begin(), module.end(), abs_sort);
		printVec(module);

		result = 1;
		//Will be positive
		if(positives >= 1){
			int result_positive = 0, result_negative = 0;
			int last_positive, last_negative;
			vector<int> ans;

			for(int i=n-1; i>=0; i--){
				if(module[i] > 0){
					last_positive = module[i];
					result_positive++;
				} else{
					last_negative = module[i];
					result_negative++;
				}
				ans.push_back(module[i]);
			}

			if(result_negative % 2 != 0){
				int first_positive = -1, first_negative = 1;
				for(int i=n-6; i>=0; i--){
					if(first_positive == -1 and module[i] > 0){
						first_positive = module[i];
					}
					if(first_negative == 1 and module[i] < 0){
						first_negative = module[i];
					}
				}

				if(first_positive != -1 and first_negative != 1){
					// if(abs())
				}

			}

		}
		else if(zeros == 0){
			for(int i=0; i<5; i++){
				result *= module[i];
			}
		}
		else{
			result = 0;
		}
		
		cout << result << endl; 
		module.clear();
		t--;
	}


	return 0;
}