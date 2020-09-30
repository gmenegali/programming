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

    cin >> n;
    for(int i=0; i<n; i++){
        cin >> x;
        testCase.push_back(x);
    }
    unordered_set<ll> seen;
    int count = 0;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum += testCase[i];
        
        if(sum == 0 or seen.find(sum) != seen.end()){
            count++;
            sum = testCase[i];
            seen.clear();
        }
        seen.emplace(sum);

    }
    cout << count << endl;
    seen.clear();
    testCase.clear();


    return 0;
}