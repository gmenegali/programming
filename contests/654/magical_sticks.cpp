#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int magical_sticks(int i){
  if(i == 1) return 1;
  if(i%2 ==0){
    return i/2;
  } else {
    return ((i-1)/2)+1;
  }
}

int main(){
  int n, t;
  cin >> n;
  while(n){
    cin >> t;
    cout << magical_sticks(t) << endl;
    n--;
  }

  return 0;
}