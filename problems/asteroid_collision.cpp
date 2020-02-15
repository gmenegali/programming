// We are given an array asteroids of integers representing asteroids in a row.
// For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). 
// Each asteroid moves at the same speed.
// Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. 
// If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
  for(int x: vec) cout << x << " ";
  cout << endl;
}

bool will_collide(int left, int right){
  if(left > 0 and right > 0) return false;
  else if(left < 0 and right < 0) return false;
  else if(left < 0 and right > 0) return false;
  else return true;
}

vector<int> asteroidCollision(vector<int>& asteroids) {
  int n = (int) asteroids.size();
  vector<int> result;
  result.push_back(asteroids[0]);

  for(int i=1; i<n; i++){
    if((int) result.size() > 0 and will_collide(result[(int) result.size() -1], asteroids[i])){
      while((int) result.size() > 0 and asteroids[i] != 0 and will_collide(result[(int) result.size() -1], asteroids[i])){
        if(abs(result[(int) result.size() -1]) > abs(asteroids[i])) asteroids[i] = 0; //Marks that isn't necessary to append asteroids[i]
        else if(abs(result[(int) result.size() -1]) < abs(asteroids[i])) result.pop_back();
        else{
          asteroids[i] = 0; //both are equal, then don't need to append asteroids[i]
          result.pop_back();
        }
      }
      if(asteroids[i] != 0) result.push_back(asteroids[i]);
    }
    else result.push_back(asteroids[i]);
  }

  return result;
}

int main(){
  // vector<int> asteroids = {-5, 10, -15, 22, -30, 5, -1, 10};
  vector<int> asteroids = {1,-1,-2,-2};
  // vector<int> asteroids = {-2,-1,1,2};
  vector<int> result = asteroidCollision(asteroids);

  print_vec(result);

  return 0;
}