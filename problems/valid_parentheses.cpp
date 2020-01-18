#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isComplement(char open, char close){
  if(open == '(' and close == ')') return true;
  if(open == '[' and close == ']') return true;
  if(open == '{' and close == '}') return true;
  return false;
}

bool isValid(string s){
  stack<char> st;

  for(int i=0; i<(int) s.size(); i++){
    if(s[i] == '(' or s[i] == '[' or s[i] == '{') st.push(s[i]);
    else if(!st.empty() and isComplement(st.top(), s[i])) st.pop(); 
    else return false;
  }

  if(!st.empty()) return false;
  return true;
}

int main(){
  string s = "()[{]}";
  bool ans = isValid(s);

  if(ans == true) cout << "valido" << endl;
  if(ans == false) cout << "invalido" << endl;


  return 0;
}