#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

void printVec(vector<ll> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(){
    int t;
    ll x, limit=1, div2=2;
    vector<ll> testCase;
    
    while(limit <= 1e18){
        testCase.push_back(limit);
        limit = (ll) (2*limit + (div2*div2));
        div2 *= 2; 
    }

    // cout << testCase.size() << endl;
    printVec(testCase);

    cin >> t;
    while(t){
        cin >> x;
        int count = 0;
        for(int i=0; i<(int)testCase.size(); i++){
            if(x>=testCase[i]){
                x -= testCase[i];
                count++;
            } else{
                break;
            }
        }

        cout << count << endl;
        t--;
    }


    return 0;
}