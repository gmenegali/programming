// Given an encoded string, return its decoded string.
// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.
// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string decodeStringOperator(string s, int mult) {
  string ans = "";
  string target = "";
  for(int i=0; i<(int)s.size(); i++){
    if(s[i] >= '0' and s[i] <= '9'){
      while(s[i] >= '0' and s[i] <= '9'){
        target.push_back(s[i]);
        i++;
      }
      i++; // Get the '[' caracter
      int open_braces = 1 , closed_braces = 0;
      
      mult = atoi(target.c_str());

      //Get the string that will be multiplied
      target = "";
      while(open_braces != closed_braces){
        if(s[i] == '[') open_braces++;
        if(s[i] == ']') closed_braces++;

        //Avoid the last ']' caracter
        if(open_braces == closed_braces) break;
        target.push_back(s[i]);
        i++;
      }

      //Decode
      while(mult){
        string partial_result = decodeStringOperator(target, mult);
        ans.append(partial_result);
        mult--; 
      }
      
      target = "";
    }
  
    //Caracters without multipliers
    else ans.push_back(s[i]);
  }
  return ans;
}

string decodeString(string s) {
  string ans = "";
  ans = decodeStringOperator(s, 1);
  return ans;
}

int main(){
  // string s = "3[a2[c]]";
  string s = "2[abc]3[cd]ef";
  string ans = "";
  cout << decodeString(s) << endl;

  return 0;
}