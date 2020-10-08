#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
void printVec(vector<int> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int open = 0;
        string result = "";
        for(int i=0; i<(int)s.size(); i++){
            if(s[i] == '('){
                result.push_back(s[i]);
                open++;
            }
            else if(s[i] == ')'){
                if(open > 0){
                    open--;
                    result.push_back(s[i]);
                }
            }
            else{
                result.push_back(s[i]);
            }
        }
        
        int j = (int) result.size()-1;
        while(open){
            if(result[j] == '('){
                result.erase(result.begin()+j);
                open--;
            }
            if(j>0){
                j--;
            }
        }


        return result;
    }
};
 
int main(){
   string s;
   cin >> s;

   Solution sol;
   cout << sol.minRemoveToMakeValid(s) << endl;
 
    return 0;
}