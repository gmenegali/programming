// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)
#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
#include <algorithm>

using namespace std;

void print_vec(vector<int> vec){
  for(int x : vec) cout << x << " ";
  cout << endl;
}

float dist(int x, int y){ return sqrt(x*x + y*y);}

vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
  vector<vector<int>> result;
  vector<tuple<int,int,float>> tuples;

  //Calculate de distances
  for(vector<int> point : points){
    tuple<int,int,float> t = make_tuple(point[0], point[1], dist(point[0], point[1]));
    tuples.push_back(t);
  }

  //Sort them by distance
  sort(tuples.begin(), tuples.end(), [](tuple<int,int,float> a, tuple<int,int,float> b) -> bool {
    return get<2>(a) < get<2>(b);
  });

  //Save the K first points
  for(int i=0; i<K; i++){
    vector<int> partial_result = {get<0>(tuples[i]), get<1>(tuples[i])};
    result.push_back(partial_result);
  }

  return result;
}

int main(){
  int k = 2;
  
  vector<vector<int>> points = {
    {3,3},
    {5,-1},
    {-2,4}
  };

  vector<vector<int>> results = kClosest(points, k);
  for(vector<int> result : results) print_vec(result);


  return 0;
}