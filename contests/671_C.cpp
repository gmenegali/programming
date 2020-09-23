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
    int t, n, x, y;
    vector<int> testCase;

    cin >> t;
    while(t){
        cin >> n >> x;
        
        int difference = 0;
        bool one_infected = false;
        bool all_equal = true;
        for(int i=0; i<n; i++){
            cin >> y;
            if(all_equal and y != x){
                all_equal = false;
            }
            if(!one_infected and x == y){
                one_infected = true;
            }
            difference += (x-y);
            testCase.push_back(y);
        }
        if(difference == 0 or one_infected){
            if(all_equal){
                cout << 0 << endl;
            }
            else{
                cout << 1 << endl;
            }
        }
        else{
            cout << 2 << endl;
        }


        testCase.clear();
        t--;
    }


    return 0;
}