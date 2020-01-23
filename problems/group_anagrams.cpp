// Given an array of strings, group anagrams together.
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

void print_vec(vector<string> vec){
  for(string x : vec) cout << x << " ";
  cout << endl;
}

vector<vector<string>> groupAnagrams(vector<string>& strs){
  vector<vector<string>> result;
  unordered_map<string,vector<string>> hash;

  for(string word_sorted : strs){
    string word = word_sorted;
    sort(word_sorted.begin(), word_sorted.end());
    
    if(hash.find(word_sorted) != hash.end()){
      (hash[word_sorted]).push_back(word);
    }
    else{
      vector<string> anagrams;
      anagrams.push_back(word);
      hash.emplace(word_sorted, anagrams);
    }
  }

  auto it = hash.begin();
  while(it != hash.end()){
    vector<string> vec = it->second;
    result.push_back(vec);
    it++;
  }

  return result;
}

int main(){
  vector<string> vec = {"eat", "tea", "tan", "ate", "nat", "bat"};
  vector<vector<string>> result = groupAnagrams(vec);

  for(vector<string> anagrams : result){
    for(string word : anagrams) cout << word << " ";
    cout << endl;
  }


  return 0;
}