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
    cin >> t;
    while(t){
        unordered_set<int> s;
        cin >> n >> k;
        for(int i=0; i<n; i++){
            cin >> x;
            s.emplace(x);
        }
 
        int size = (int) s.size();
        // cout << size << " " << k << endl;
        if(k >= size){
            cout << 1 << endl;
        }
        else if(k == 1){
            cout << -1 << endl;
        }
        else{
            //First take k different
            int result = 1;
            size = max(0, size-k);
 
            //Later take k-1 different
            result += size/(k-1) + (size % (k-1) != 0);
            cout << result  << endl;
        }
 
        s.clear();
        t--;
    }
 
 
    return 0;
}