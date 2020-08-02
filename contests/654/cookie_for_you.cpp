#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
string cookie_for_you(long long a, long long b, long long n, long long m){
  if(a + b < n + m) return "no"; // Is there enough cookies for everybody?
  if(a < m  or b < m) return "no"; // Is there enough cookies for the jerks?

  long long balanced = min(n, m);
  a -= balanced;
  b -= balanced;
  m -= balanced;
  n -= balanced;

  if(a < 0 or b < 0) return "no"; // Not enough cookies 
  if(m > a or m > b) return "no"; // Not enough cookies

  return "yes";
}

int main(){
  long long t, a, b, n, m;
  cin >> t;
  while(t){
    cin >> a >> b >> n >> m;
    cout << cookie_for_you(a, b, n, m) << endl;
    t--;
  }
  
  return 0;
}