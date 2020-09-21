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
    int n, x, t;
    vector<int> testCase;

    // cin >> t;
    // while(t){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            testCase.push_back(x);
        }

        sort(testCase.begin(), testCase.end());

        int i=0, j=n-1;
        vector<int> result;

        while(j >= i){
            result.push_back(testCase[j]);
            j--;
            if(j > i){
                result.push_back(testCase[i]);
                i++;
            }
        }
        if(n%2 != 0){
            cout << n/2 << endl;
        }
        else{
            cout << (n-1)/2 << endl;
        }
        printVec(result);

        testCase.clear();
        result.clear();
        // t--;
    // }

    return 0;
}