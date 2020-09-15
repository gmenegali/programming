#include <iostream>
#include <vector>

using namespace std;

/**
 * Return the index of the target, or '-1'
 * if the number isn't in the vector
 */
int binary_search(vector<int> &nums, int min, int max, int target){
  if(min > max) //Failed 
  return -1; 

  int middle = min + ((max-min)/2);
  if(nums[middle] == target)
    return middle;

  if(nums[middle] > target)
    return binary_search(nums, min, middle-1, target);
  if(nums[middle] < target)
    return binary_search(nums, middle+1, max, target);

  return -1;
}


int main(){
  vector<int> vec = {1,2,6,9};
  cout << binary_search(vec, 0, 3, 1) << endl;
  cout << binary_search(vec, 0, 3, 2) << endl;
  cout << binary_search(vec, 0, 3, 6) << endl;
  cout << binary_search(vec, 0, 3, 9) << endl;
  cout << binary_search(vec, 0, 3, 0) << endl;
  cout << binary_search(vec, 0, 3, 10) << endl;
  cout << binary_search(vec, 0, 3, 3) << endl;

  return 0;
}