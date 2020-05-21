// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.
// Note: The solution set must not contain duplicate triplets.

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;


class Solution{
public:

  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    unordered_set<int> seen; //Used to search a pair in O(n)
    unordered_set<int> targets_searched; //Avoid to repeat the same search
    set<pair<int,int>> pairs_found; //A pair represents efficiently a triplet 

    for(int i=0; i < (int) nums.size(); i++){
      int target = -nums[i];

      if(targets_searched.find(target) == targets_searched.end()){
        seen.clear();
        for(int j=i+1; j < (int) nums.size(); j++){
          if(seen.find(target - nums[j]) != seen.end()){
            pair<int,int> possible_pair = make_pair(min( min(nums[i], nums[j]), target-nums[j]), max( max(nums[i], nums[j]), target-nums[j]));
            pairs_found.insert(possible_pair);
          }
          seen.emplace(nums[j]);
        }
        targets_searched.emplace(target);
      }
    }

    for(auto it=pairs_found.begin(); it != pairs_found.end(); it++){
      vector<int> individual_result = {(it)->first, (it)->second, -((it)->first + (it)->second)};
      result.push_back(individual_result);
    }

    return result;
  }
};


int main(){
  vector<int> v = {-1,0,1,2,-1,4};

  Solution s;
  s.threeSum(v);

  return 0;
}
