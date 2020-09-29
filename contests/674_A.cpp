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

    cin >> t;
    while(t){
        cin >> n >> x;
        if(n < 3)
            cout << "1" << endl;
        else{
            n -= 3;
            cout << (n / x )+2 << endl;
        }
        t--;
    }


    return 0;
}