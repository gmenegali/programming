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
    int t, n, m, x;
    unordered_set<int> testCase;
 
    cin >> t;
    while(t){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            cin >> x;
            testCase.emplace(x);
        }
        int result = -1;
        for(int i=0; i<m; i++){
            cin >> x;
            if(result == -1 and testCase.find(x) != testCase.end())
                result = x;
        }

        if(result == -1){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << 1 << " " << result << endl;

        }

        testCase.clear();
        t--;
    }
 
    return 0;
}