#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long magical_calendar(long long n, long long r){
  long long result = 0;
  if(n <= r){
    result = 1+(n*(n-1)/2);
  } else {
    result = (long long) (((r+1)*r)/2);
  }
  return result;
}

int main(){
  long long t, n, r;
  cin >> t;
  while(t){
    cin >> n >> r;
    cout << magical_calendar(n, r) << endl;
    t--;
  }

  return 0;
}

