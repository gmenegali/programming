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
    int t, n, k, x;
    vector<int> testCase;

    cin >> t;
    while(t){
        cin >> n >> k;
        int minimum = INT_MAX;
        int minimum_i = -1;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x < minimum){
                minimum = x;
                minimum_i = i;
            }
            testCase.push_back(x);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(k - testCase[i] > 0 and minimum_i != i)
                count += (k - testCase[i]) / minimum;
        }

        cout << count << endl;
        testCase.clear();
        t--;
    }


    return 0;
}