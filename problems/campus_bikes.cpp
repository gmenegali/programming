// On a campus represented as a 2D grid, there are N workers and M bikes, with N <= M. Each worker and bike is a 2D coordinate on this grid.
// Our goal is to assign a bike to each worker. Among the available bikes and workers, we choose the (worker, bike) pair with the shortest Manhattan distance between each other, and assign the bike to that worker. (If there are multiple (worker, bike) pairs with the same shortest Manhattan distance, we choose the pair with the smallest worker index; if there are multiple ways to do that, we choose the pair with the smallest bike index). We repeat this process until there are no available workers.
// The Manhattan distance between two points p1 and p2 is Manhattan(p1, p2) = |p1.x - p2.x| + |p1.y - p2.y|.
// Return a vector ans of length N, where ans[i] is the index (0-indexed) of the bike that the i-th worker is assigned to.
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec){
  for(int x: vec) cout << x << " ";
  cout << endl;
}

int manhattan_distance(vector<int> p1, vector<int> p2){
  return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
}

vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes){
  int n = (int) workers.size();
  int m = (int) bikes.size();

  vector<int> ans(n, -1);
  vector<int> bikes_used(m, 0);
  vector<vector<int>> distances;

  for(int i=0; i < n; i++){
    for(int j=0; j < m; j++){
      distances.push_back({manhattan_distance(workers[i], bikes[j]), i, j});
    }
  }

  sort(distances.begin(), distances.end(), [](vector<int> &a, vector<int> & b) -> bool{ 
      if(a[0] != b[0]) return a[0] < b[0];
      else if(a[1] != b[1]) return a[1] < b[1];
      else return a[2] < b[2];
  });

  for(int i=0; i<(int)distances.size(); i++){
    if(ans[distances[i][1]] == -1 and bikes_used[distances[i][2]] == 0){
      ans[distances[i][1]] = distances[i][2];
      bikes_used[distances[i][2]] = 1;
    }
  }

  return ans;
}

int main(){
  vector<vector<int>> workers = {{664,994},{3,425},{599,913},{220,352},{145,348},{604,428},{519,183},{732,148}};
  vector<vector<int>> bikes = {{611,698},{113,338},{579,770},{276,588},{948,679},{731,525},{925,877},{182,281},{39,299}};
  // vector<vector<int>> workers = {{0,0},{1,1}, {2,0}};
  // vector<vector<int>> bikes = {{1,0},{2,2}, {2,1}};

  vector<int> ans = assignBikes(workers, bikes);
  print_vec(ans);

  return 0;
}