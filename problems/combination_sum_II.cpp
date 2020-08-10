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

class Solution {
public:
	vector<vector<int>> result;
	vector<int> current;

	void combinationSum2Cal(vector<int>& candidates, int candidates_index, int target){
		if(target == 0){
			result.push_back(current);
		} else if(target < 0) {
			return;
		}

		for(int i=candidates_index; i < (int) candidates.size(); i++){
			current.push_back(candidates[i]);
			combinationSum2Cal(candidates, i+1, target-candidates[i]);
			while(i < (int) candidates.size() -1 and candidates[i] == candidates[i+1]){
				i++;
			}
			current.pop_back();
  	}


	}

  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  	sort(candidates.begin(), candidates.end());
  	current = {};
  	combinationSum2Cal(candidates, 0, target);
    return result;
  }
};


int main(){
	vector<int> candidates = {10,1,2,7,6,1,5};
	int target = 8;

	
	// printVec(candidates);
	Solution s;
	vector<vector<int>> result =	s.combinationSum2(candidates, target);
	for(vector<int> ans : result){
		printVec(ans);
	}

	return 0;
}