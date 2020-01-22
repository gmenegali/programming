// In a row of dominoes, A[i] and B[i] represent the top and bottom halves of the i-th domino.  (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
// We may rotate the i-th domino, so that A[i] and B[i] swap values.
// Return the minimum number of rotations so that all the values in A are the same, or all the values in B are the same.
// If it cannot be done, return -1.
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#define min(a,b) (a < b? a:b)

void print_vec(vector<int> vec){
  for(int x : vec) cout << x << " ";
  cout << endl;
}

vector<int> get_targets(vector<int>& A, vector<int>& B){
  vector<int> possible_targets;
  vector<int> number_count(7,0);

  int num_dominos = (int) A.size();

  for(int i=0; i < num_dominos; i++){
    if(A[i] == B[i]) number_count[A[i]]++;
    else{
      number_count[A[i]]++;
      number_count[B[i]]++;
    }
  }

  for(int i=0; i < 7; i++){
    if(number_count[i] == num_dominos) possible_targets.push_back(i);
  }
  
  return possible_targets;
}

int minDominoRotations(vector<int>& A, vector<int>& B){
  vector<int> targets = get_targets(A,B);
  if( (int)targets.size() == 0) return -1;
  int num_dominos = (int) A.size();

  int min_moves_possible = INT_MAX;
  for(int target: targets){
    int target_count_A = 0;
    int target_count_B = 0;
    for(int i=0; i < num_dominos; i++){
      if(A[i] == target) target_count_A++;
      if(B[i] == target) target_count_B++;
    }
    int min_moves_target = min(num_dominos - target_count_A, num_dominos - target_count_B);
    min_moves_possible = min(min_moves_possible, min_moves_target);
  }
  
  return min_moves_possible;
}


int main(){
  vector<int> A = {6,1,6,4,6,6}, B = {5,6,2,6,3,6};
  // vector<int> A = {2,1,2,4,2,2}, B = {5,2,6,2,3,2};
  cout << minDominoRotations(A,B) << endl;
  // print_vec(A);
  // print_vec(B);


  return 0;
}
