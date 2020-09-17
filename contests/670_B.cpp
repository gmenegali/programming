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
	return abs(a) > abs(b);
}

int main(){
	int t, n, x;
	ll result = 1;
	vector<int> module;
	// int a;
		
	cin >> t;
	while(t){
		cin >> n;
		int zeros = 0;
		int positives = 0;
		for(int i=0; i<n; i++){
			cin >> x;

			if(x > 0)
				positives++;
			if(x == 0)
				zeros++;
			module.push_back(x);
		}

		result = 1;
		sort(module.begin(), module.end(), abs_sort);
		// printVec(module);

		if(positives > 0){
			int negatives = 0, i_last_negative = -1, i_last_positive = -1;
			for(int i=0; i<5; i++){			
				result *= module[i];
				if(module[i] > 0){
					i_last_positive = i;
				}

				if(module[i] < 0){
					i_last_negative = i;
					negatives++;
				}
			}

			int i_first_positive = -1, i_first_negative = -1;
			for(int i=5; i<n; i++){			
				if(i_first_positive == -1 and module[i] > 0){
					i_first_positive = i;
				}
				if(i_first_negative == -1 and module[i] < 0){
					i_first_negative = i;
				}
			}

			ll possible_result1 = 1, possible_result2 = 1;
			if(i_last_negative != -1 and i_first_positive != -1){
				swap(module[i_last_negative], module[i_first_positive]);
				for(int i=0; i<5; i++){			
					possible_result1 *= module[i];
				}		
				swap(module[i_last_negative], module[i_first_positive]);
				result = max(result, possible_result1);
			}

			if(i_last_positive != -1 and i_first_negative != -1){
				swap(module[i_last_positive], module[i_first_negative]);
				for(int i=0; i<5; i++){			
					possible_result2 *= module[i];
				}
				swap(module[i_last_positive], module[i_first_negative]);
				result = max(result, possible_result2);
			}
		}
		else{
			for(int i=n-1; i>=n-5; i--){			
				result *= module[i];
			}
		}

		if(zeros > 0)
			result = max(result, (ll) 0);

		cout << result << endl; 
		// cout << negatives << " " << n << endl << endl;
		module.clear();
		t--;
	}


	return 0;
}