#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
template <class vector_type>
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
        vector<int> testCase;
        int n, k, x;
        cin >> n >> k;
 
        for(int i=0; i<n; i++){
            cin >> x;
            testCase.push_back(x);
        }

        
        sort(testCase.rbegin(), testCase.rend());

        ll sum = 0;
        for(int i=0; i<k+1; i++){
            sum += testCase[i];
        }

        cout << sum << endl;

        t--;
    }
 
    return 0;
}