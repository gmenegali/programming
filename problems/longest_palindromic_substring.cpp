//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
#include <iostream>
#include <string>
#include <stack>

using namespace std;

#define min(a,b) (a < b? a : b)

string longestPalindrome(string s){
  int str_size = (int) s.size();
  string first_part, second_part, result="";

  for(int i=1; i < str_size; i++){
    first_part = s.substr(0,i);
    second_part = s.substr(i,str_size);

    int f_part_size = (int) first_part.size();
    int s_part_size = (int) second_part.size();
    string even_result = "";
    string odd_result = "";

    //Even size palindrome
    for(int j=0; j< min(f_part_size, s_part_size); j++){
      if(second_part[j] != first_part[f_part_size - j - 1]) break;
      even_result.insert(even_result.begin(),second_part[j]);
      even_result.push_back(second_part[j]);
    }

    //Odd size palindrome
    if(s_part_size > 1 and second_part[1] == first_part[f_part_size - 1]){
      odd_result.push_back(second_part[0]);
      for(int j=0; j< min(f_part_size, s_part_size-1); j++){
        if(second_part[j+1] != first_part[f_part_size - j - 1]) break;
        odd_result.insert(odd_result.begin(),second_part[j+1]);
        odd_result.push_back(second_part[j+1]);
      }
    }

    if(odd_result.size() > result.size()) result = odd_result;
    if(even_result.size() > result.size()) result = even_result;
  }

  if(result == "") result.push_back(s[0]);

  return result;
}

int main(){
  string s = "babad";
  // string s = "forgeeksskeegfor";
  string ans = longestPalindrome(s);

  cout << ans << endl;

  return 0;
}