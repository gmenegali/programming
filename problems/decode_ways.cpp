// A message containing letters from A-Z is being encoded to numbers using the following mapping:
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <unordered_map>

using namespace std;

unordered_map<string, int> dp;

int numDecodings(string num){
  int counter = 0;

  if(num.size() == 0) return 1;
  if(num.size() == 1 and num[0] != '0') return 1;

  //Get the one char path, if possible
  string cpy = num;
  if(num.size() > 1 and num[0] != '0' and num[1] != '0'){
    cpy.erase(0,1);
    if(dp.find(cpy) != dp.end()) counter += dp[cpy];
    else{
      counter += numDecodings(cpy);
      dp[cpy] = counter;
    }
  }


  //Get the two chars path, if possible
  cpy = num;
  if(num.size() > 1 and (num[0] == '1' or num[0] == '2') ){
    if(num[0] == '1' or (num[0] == '2' and num[1] <= '6') ){
      cpy.erase(0,2);
      if(dp.find(cpy) != dp.end()) counter += dp[cpy];
      else{
        counter += numDecodings(cpy);
        dp[cpy] = counter;
      }
    }
  }

  return counter;
}

int main(){
  string s = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
  int result = numDecodings(s);

  cout << "result = " << result << endl;
  return 0;
}