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
 
int main(){
    string s;
    cin >> s;
 
    int length = (int) s.size();
    int i=0;
    int j = length-1;
 
    int result = 0;
    while(i<j){
        if(s[i] != s[j]){
            result++;
        }
        i++;
        j--;
    }
 
    cout << result << endl;
 
    return 0;
}