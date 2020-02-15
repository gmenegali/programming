// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

#define min(a,b) (a < b ? a : b)

void print_vec(vector<int> vec){
  for(int x:vec) cout << x << " ";
  cout << endl;
}

int findMinDifference(vector<string>& timePoints) {
  vector<int> timePoints_int;

  for(string s: timePoints){
    int hour = stoi(s.substr(0,2)); 
    int minutes = stoi(s.substr(3,2)); 
    timePoints_int.push_back(60*hour + minutes);
    //The maximum possible distance is 720(12:00), so if the time is <= 12:00, we need to add
    //them (+12:00) to compare with time which are > 12:00
    if(60*hour + minutes <= 720) timePoints_int.push_back(60*hour + minutes + 1440);
  }

  sort(timePoints_int.begin(), timePoints_int.end());

  print_vec(timePoints_int);

  int min_val = INT_MAX;
  for(int i=0; i<(int)timePoints_int.size() - 1; i++) min_val = min(min_val, timePoints_int[i+1] - timePoints_int[i]);

  return min_val;
}

int main(){
  vector<string> timePoints = {"23:59","00:00"};
  int result = findMinDifference(timePoints);
  cout << result << endl;

  return 0;
}
