// Given an array nums of n integers where n > 1,  
// return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
// Example:
// Input:  [1,2,3,4]
// Output: [24,12,8,6]
// Note: Please solve it without division and in O(n).
// Follow up:
// Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)

#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
  for(int x: vec) cout << x << " ";
  cout << endl;
}

/**
 * The main ideia is to work with the product of the left and right side of an index
 */
vector<int> productExceptSelf(vector<int>& nums) {
  int nums_size = (int) nums.size();
  vector<int> result(nums_size, 1);
  vector<int> right(nums_size, 1);
  
  for(int i=1; i<nums_size; i++){
    result[i] *= result[i-1] * nums[i-1];
  }

  int right_mult = 1;
  for(int i=nums_size-1; i>=0; i--){    
    result[i] *= right_mult;
    right_mult *= nums[i];
  }

  return result;
}

int main(){
  vector<int> vec{1,2,3,4};
  productExceptSelf(vec);

  return 0;
}