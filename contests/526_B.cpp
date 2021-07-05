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
 
 
    ll n, x;
    ll s;
    vector<ll> v;
    cin >> n >> s;

    ll smaller = INT_MAX;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x < smaller) smaller = x;
        v.PB(x);
    }

    ll count = 0;
    for(int i=0; i<n; i++){
        count += v[i] - smaller;
    }

    if(s <= count){
        cout << smaller << endl;
    }
    else{
        ll turns = (s-count)/n + ((s-count)%n != 0);
        if(turns > smaller){
            cout << -1 << endl;
        }
        else{
            // cout << turns << " " << smaller << endl;
            cout << abs(turns-smaller) << endl;

        }
    }
 
    return 0;
}