#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec){
  for(int x: vec) cout << x << " ";
  cout << endl;
}

#define max(a,b) (a > b ? a : b)

/**
 * After sorting the intervals, we only have to verify if 
 * the next interval overlaps or not with the last added 
 * interval in the result. 
 */
vector<vector<int>> merge(vector<vector<int>>& intervals) {
  int intervals_size = (int) intervals.size();
  vector<vector<int>> result;

  //Sorting the intervals
  sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b){
    return a[0] < b[0];
  });

  if(intervals_size > 0) result.push_back(intervals[0]);

  int last_index = 0;
  for(int i=1; i<intervals_size; i++){
    //Overlaps
    if(result[last_index][1] >= intervals[i][0]){ 
      result[last_index][1] = max(result[last_index][1], intervals[i][1]) ;
    }

    //Separated
    else{
      result.push_back(intervals[i]);
      last_index++;
    }
  }
  return result;
}

int main(){
  // vector<vector<int>> intervals = { };
  // vector<vector<int>> intervals = { {8,10},{15,18},{1,3},{2,6} };
  vector<vector<int>> intervals = { {2,3},{4,6},{5,7},{3,4},{9,10} };
  vector<vector<int>> result = merge(intervals);

  for(int i=0; i<(int) result.size(); i++){
    print_vec(result[i]);
  }

  return 0;
}
