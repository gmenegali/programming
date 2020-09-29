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
    int t, n, m;
    vector<int> testCase;

    cin >> t;
    while(t){
        cin >> n >> m;
        int a, b, c, d;
        bool result = false;
        for(int i=0; i<n; i++){
            cin >> a >> b >> c >> d;
            if(b == c)
                result = true;
        }
        if(result and m%2 == 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        t--;
    }


    return 0;
}