// Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
#include <iostream>
#include <vector>

using namespace std;

int subarraySum(vector<int>& nums, int k) {
  int current_sum = 0, result = 0;
  int nums_size = (int) nums.size();

  for(int start=0; start<nums_size; start++){
    current_sum = 0;
    for(int end=start; end<nums_size; end++){
      current_sum += nums[end];
      if(current_sum == k) result++;
    }
  }

  return result;
}

int main(){
  vector<int> vec = {-1,-1,1};
  int k = 0;
  cout << subarraySum(vec,k) << endl;


  return 0;
}