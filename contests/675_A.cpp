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
    int t, x;
    vector<int> testCase;
 
    cin >> t;
    while(t){
        for(int i=0; i<3; i++){
            cin >> x;
            testCase.push_back(x);
        }

        sort(testCase.begin(), testCase.end());
        ll s1 = (ll) testCase[1] + (ll) testCase[2];
        ll ans = s1 - (ll) testCase[0];

        cout << ans << endl;

 
        testCase.clear();
        t--;
    }
 
    return 0;
}