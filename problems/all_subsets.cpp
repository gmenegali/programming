// Write a method to return all subsets of a set.
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
  if((int) vec.size() == 0) cout << "{}";
  else for(int x: vec) cout << x << " ";
  cout << endl;
}

vector<vector<int>> subsets(vector<int> vec, int index){
  vector<vector<int>> all_subsets;

  if(index == (int) vec.size()){ // Base case, adds an empty subset
    vector<int> empty;
    all_subsets.push_back(empty);
  }
  else{
    all_subsets = subsets(vec, index+1); //Go to the base case and then come back
    int element = vec[index]; //Create new subsets adding this element to each of previous subsets 
    vector<vector<int>> more_subsets;

    for(int i=0; i<(int) all_subsets.size(); i++){ //For each vec in all_subsets
      vector<int> temp = all_subsets[i];  
      temp.push_back(element);
      more_subsets.push_back( temp );
    }

    for(int i=0; i<(int) more_subsets.size(); i++){ //For each vec in more_subsets
      vector<int> temp = more_subsets[i];  
      all_subsets.push_back( temp );
    }
  }
  return all_subsets;
}



int main(){
  vector<int> set = {1,2,3};
  vector<vector<int>> result = subsets(set, 0);

  for(int i=0; i<(int) result.size(); i++) print_vec(result[i]);

  return 0;
}