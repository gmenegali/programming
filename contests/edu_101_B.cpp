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
        vector<int> r;
        vector<int> b;
        int n, m, x;
        cin >> n;


        int maxi = 0, current=0;
        for(int i=0; i<n; i++){
            cin >> x;
            current += x;
            
            maxi = max(maxi, current);
            r.push_back(x);
        }
        cin >> m;

        int maxi2 = 0;
        current = 0;
        for(int i=0; i<m; i++){
            cin >> x;
            current += x;
            
            maxi2 = max(maxi2, current);
            b.push_back(x);
        }

        cout << maxi2 + maxi << endl;


        t--;
    }
 
    return 0;
}