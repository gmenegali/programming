#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
 
using namespace std;
 
typedef vector<int> vi;
typedef pair<int,int> pi;
 
template <class vector_type>
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
        set<int> ns;
        vector<int> ms;
        int n, m, x;
        cin >> n >> m;
 
        for(int i=0; i<n; i++){
            cin >> x;
            ns.emplace(x);
        }

        bool result = true;
        int count = 0;
        for(int i=0; i<m; i++){
            cin >> x;
            if(ns.find(x) != ns.end()){
                result = false;
                count++;
            }
        }

        cout << count << endl;
 
        t--;
    }
 
    return 0;
}