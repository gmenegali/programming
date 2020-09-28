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
    int t, n, x, T;
    unordered_map<int, int> forbidden_c; //0
    unordered_map<int, int> forbidden_d; //1
    // unordered_set<int> c; 
    // unordered_set<int> d; 

    cin >> t;
    while(t){
        cin >> n >> T;
        for(int i=0; i<n; i++){
            cin >> x;
            if(forbidden_c.find(x) == forbidden_c.end()){
                cout << 0 << " ";
                forbidden_c.emplace(T- x, 1);
            }
            else if(forbidden_d.find(x) == forbidden_d.end()){
                cout << 1 << " ";
                forbidden_d.emplace(T- x, 1);
            }
            else{
                if(forbidden_c[x] >= forbidden_d[x]){
                    cout << 1 << " ";
                    forbidden_d[T-x]++;
                } else{
                    cout << 0 << " ";
                    forbidden_c[T-x]++;
                }
            }
        }
        cout << endl;
        forbidden_c.clear();
        forbidden_d.clear();
        t--;
    }


    return 0;
}