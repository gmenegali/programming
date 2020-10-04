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
    int n, x;
    vector<int> testCase;
    unordered_set<int> s;
 
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        s.emplace(x);
        testCase.push_back(x);
    }
 
    bool result = false;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(s.find(testCase[i]+testCase[j]) != s.end()){
                result = true;
                break;
            }
        }
    }
 
    if(result){
        cout << "SIM" << endl;
    }
    else{
        cout << "NAO" << endl;
    }
 
 
    return 0;
}