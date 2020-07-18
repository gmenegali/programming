#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  unordered_map<string, bool> memo;

  bool backtracking(string s, vector<string>& wordDict) {
    if(s.size() == 0){
      return true;
    }

    for(string word : wordDict){
      if(word[0] <= s[0]){
        if(s.find(word) == 0){
          int word_len = (int) word.size();
          int s_len = (int) s.size();
          string target = s.substr(word_len, s_len - word_len);
          
          bool return_result;
          if(memo.find(target) != memo.end()){
            return_result = memo[target]; 
          } else{
            return_result = backtracking(target, wordDict);
            memo[target] = return_result;
          }

          if(return_result)
            return true;
        }
      } else{
        break;
      }
    }
    
    return false;
  }

  bool wordBreak(string s, vector<string>& wordDict) {
    sort(wordDict.begin(), wordDict.end());
    return backtracking(s, wordDict);
  }
};

int main(){

  // string s1 = "catsandog";
  // vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
  string s1 = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
  vector<string> wordDict = {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  // string s = "applepenapple";
  // vector<string> wordDict = {"apple", "pen"};

  Solution s;
  cout << s.wordBreak(s1, wordDict) << endl;
  // cout << s.backtracking(s1, wordDict) << endl;

  return 0;
}