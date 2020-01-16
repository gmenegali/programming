// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec){
  for(int x : vec) cout << x << " ";
  cout << endl;
}

/**
 * Brute force algorithm
 */
vector<int> twoSum_brute(vector<int>& nums, int target) {
  int nums_size = (int) nums.size();
  vector<int> result;

  for(int i=0; i < nums_size; i++){
    for(int j=i+1; j < nums_size; j++){
      if(nums[i]+nums[j] == target){
        result.push_back(i);
        result.push_back(j);
      }
    }
  }
  return result;
}

int binary_search(vector<int> &nums, int min, int max, int target){
  if(min > max) return -1; //Failed

  int middle = (min+max)/2;
  if(nums[middle] == target) return middle;

  if(nums[middle] > target) return binary_search(nums, min, middle-1, target);
  if(nums[middle] < target) return binary_search(nums, middle+1, max, target);

  return -1;
}

/**
 * We can improve the efficiency by sorting the vector 
 * and then calling multiple binary searchs to find
 * if there is the complement of the number
 */
vector<int> twoSum_binary_search(vector<int>& nums, int target) {
  int nums_size = (int) nums.size();
  vector<int> result;

  vector<int> nums_sorted = nums;
  sort(nums_sorted.begin(), nums_sorted.end());

  for(int i=0; i < nums_size; i++){
    int complement = target - nums_sorted[i];
    int search_result = binary_search(nums_sorted, 0, nums_size, complement);
    if(search_result != -1){
      result.push_back(nums_sorted[i]);
      result.push_back(nums_sorted[search_result]);
      break;
    }
  }

  // Change the values for the indexes
  for(int i=0; i < nums_size; i++){
    if(result[0] == nums[i]) result[0] = i;
    if(result[1] == nums[i]) result[1] = i;
  }

  return result;
}

/**
 * Auxliar function used in twoSum_hase
 */
bool has_duplicates(vector<int> &nums, int target){
  int nums_size = (int) nums.size();
  int count = 0;

  for(int i=0; i < nums_size; i++){
    if(nums[i] == target) count++;
    if(count > 1) return true;
  }
  return false;
}

/**
 * Uses a hash table to make the look up faster
 */
vector<int> twoSum_hash(vector<int>& nums, int target) {
  int nums_size = (int) nums.size();
  vector<vector<int>> hash(nums_size);
  vector<int> result;

  //add values to hash
  for(int i=0; i < nums_size; i++){
    if(nums[i] >= 0) (hash[nums[i] % nums_size]).push_back(nums[i]);
    else (hash[(-nums[i]) % nums_size]).push_back(nums[i]);
  }

  //Verify if each complement is in hash
  for(int i=0; i < nums_size; i++){
    vector<int> search_vector;
    int complement = target - nums[i];
    if(complement < 0) search_vector = hash[(-complement) % nums_size];
    else search_vector = hash[complement % nums_size];

    //Avoid problems in the hash where the complement is the number itself
    if(complement == nums[i] and !has_duplicates(search_vector, complement)) continue;

    bool found = false; //Avoid the problem of adding the answer more than once
    for(int j=0; j < (int) search_vector.size(); j++){
      if(search_vector[j] == complement){
        result.push_back(nums[i]);
        result.push_back(complement);
        found = true;
        break;
      }
    }
    if(found == true) break;
  }

  // Change the values for the indexes
  if(result[0] == result[1]){
    int status = 0; //'0'-not find, '1'- found first, '2' -looking for second, '3' found second
    int targ = result[0];
    for(int i=0; i < nums_size; i++){
      if(targ == nums[i]) status++;
      if(status == 1){
        result[0] = i;
        status++; 
      }
      if(status == 3){
        result[1] = i;
        break;
      } 
    }
  }
  else{
    //First index
    for(int i=0; i < nums_size; i++){
      if(result[0] == nums[i]){
        result[0] = i;
        break;
      } 
    }
    //Second index
    for(int i=0; i < nums_size; i++){
      if(result[1] == nums[i]){
        result[1] = i;
        break;
      } 
    }
  }

  return result;
}

int main(){
  vector<int> vec = {3,2,3};
  // vector<int> vec = {0,3,-3,4,-1};
  // vector<int> vec = {-3,4,3,90};
  // vector<int> vec = {3,2,4};
  // vector<int> vec = {3,3};
  // vector<int> result = twoSum_brute(vec, 10);
  // vector<int> result = twoSum_binary_search(vec, 10);
  vector<int> result = twoSum_hash(vec, 6);

  print_vec(result);

  return 0;
}