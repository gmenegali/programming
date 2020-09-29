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
    int t, n;

    cin >> t;
    while(t){
        cin >> n;
        int current, last = INT_MAX;
        for(int i=1; i<=n; i++){
            current = i-1;
            int steps = n/i + (n % i != 0);
            current += steps -1;
            if(last < current){
                break;
            }
            last = current;
        }
        cout << last << endl;
        t--;
    }


    return 0;
}