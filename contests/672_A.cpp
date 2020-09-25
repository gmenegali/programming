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
    int t, n, x;
    vector<int> testCase;

    cin >> t;
    while(t){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            testCase.push_back(x);
        }
        vector<int> w = testCase;

        int count = 0;
        for(int i=0; i<n; i++){
            if(i+1 < n and testCase[i] > testCase[i+1]){
                count++;                
            }
        }
        sort(testCase.begin(), testCase.end());
        bool repeated = false;
        for(int i=0; i<n; i++){
            if(i+1 < n and testCase[i] == testCase[i+1]){
                repeated = true;
                break;
            }
        }

        if(count < n - 1 or repeated == true)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

        testCase.clear();
        t--;
    }

    return 0;
}