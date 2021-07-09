#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define len(s) (int) s.size()
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
 
        int n, m, x;
        vector<pair<int,int>> vp;
        cin >> n >> m;

        for(int i=0; i<n; i++){
            cin >> x;
            vp.PB(make_pair(x, i+1));
        }
        

        if(n > m or n == 2){
            cout << -1 << endl;
        }
        else{
            sort(vp.begin(), vp.end());
            ll total = 0;
            for(int i=0; i<n-(n-m)-1; i++){
                total += vp[i].F + vp[i+1].F;
            }
            total += vp[n-1].F + vp[0].F;

            cout << total << endl;
            for(int i=0; i<n-(n-m)-1; i++){
                cout << vp[i].S << " " << vp[i+1].S << endl;
            }
            cout << vp[n-1].S << " " << vp[0].S << endl;
        }
        
        t--;
    }
 
    return 0;
}