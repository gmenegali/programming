#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int> v){
  for(int i=0; i < (int) v.size(); i++){
    cout << v[i] << " ";
  }
  cout << endl;
}

void asterism_easy(vector<int> enemies, int max_x, int n, int p){
  int counter, positions_used;
  vector<int> ans;
  bool valid;

  for(int i = max_x-n+1; i<max_x; i++){ // candidates
    positions_used = 0;
    valid = true;

    // Count how many positions are avaiable
    for(int j=0; j<n; j++){ // enemies
      if(enemies[j] - i > 0){
        counter = n-(enemies[j] - i);
      } else {
        counter = n;
      }
      if( (counter - positions_used) % p == 0){
        valid = false;
      }
      positions_used++;
    }

    if(valid){
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  print_vec(ans);

}

int main(){
  int n, p;
  cin >> n >> p;

  vector<int> enemies(n);

  int max_candies = INT_MIN;
  for(int i=0; i<n; i++){
    cin >> enemies[i];
    if(enemies[i] > max_candies) 
      max_candies = enemies[i];
  }
  sort(enemies.begin(), enemies.end(), greater<int>());
  asterism_easy(enemies, max_candies, n, p);

  return 0;
}