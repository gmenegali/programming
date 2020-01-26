// Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
// A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_vec(vector<string> vec){
  for(string x : vec) cout << x << " ";
  cout << endl;
}

vector<string> letterCombinationsOperator(vector<string> &new_letters, vector<string> current_result){
  vector<string> result;

  //Handle the first letter
  if((int)current_result.size() == 0){
    for(string letter : new_letters){
      string new_string = letter;
      result.push_back(new_string);
    }
  }
  //All the other cases
  else{
    for(string item : current_result){
      for(string letter : new_letters){
        string new_string = item;
        new_string.append(letter);
        result.push_back(new_string);
      }    
    }
  }

  return result;
}

vector<string> letterCombinations(string digits){
  vector<string> result;

  vector<vector<string>> phone = {
    {},
    {},
    {"a","b","c"},
    {"d", "e", "f"},
    {"g", "h", "i"},
    {"j", "k", "l"},
    {"m", "n", "o"},
    {"p", "q", "r", "s"},
    {"t", "u", "v"},
    {"w", "x", "y", "z"}
  };

  for(int i=0; i<(int) digits.size(); i++){
    vector<string> new_letters = phone[digits[i] - 48];
    result = letterCombinationsOperator(new_letters, result);
  }

  return result;
}


int main(){
  string s = "234";
  vector<string> result = letterCombinations(s);
  print_vec(result);

  return 0;
}
