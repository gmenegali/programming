
// Given an array of non-negative integers, you are initially positioned at the first index of the array.
// Each element in the array represents your maximum jump length at that position.
// Determine if you are able to reach the last index.
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
  for(int x : vec) cout << x << " ";
  cout << endl;
}

/**
 * Using the auxilar vector "has_path" to
 * mark the positions that can reach the end.
 * 
 */
bool canJump(vector<int>& nums) {
  int nums_size = (int) nums.size();
  vector<int> has_path(nums_size, 0);
  has_path[nums_size-1] = 1;

  for(int i=nums_size-2; i>=0; i--){
    if(nums[i] == 0) continue;
    else{
      int value = nums[i];
      while(value){
        if( (i+value > (int) nums_size-1) or (has_path[i+value] != 0) ) has_path[i] = 1;
        value--;
      } 
    }
  }
  if(has_path[0] == 1) return true;
  else return false;
}

int main(){
  vector<int> vec = {2,0,6,9,8,4,5,0,8,9,1,2,9,6,8,8,0,6,3,1,2,2,1,2,6,5,3,1,2,2,6,4,2,4,3,0,0,3,8,2,4,0,1,2,0,1,4,6,5,8,0,7,9,3,4,6,6,5,8,9,3,4,3,7,0,4,9,0,9,8,4,3,0,7,7,1,9,1,9,4,9,0,1,9,5,7,7,1,5,8,2,8,2,6,8,2,2,7,5,1,7,9,6};
  bool ans = canJump(vec);

  if(ans == true) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}