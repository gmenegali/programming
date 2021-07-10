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
    int n, a;
    vi v;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> a;
        v.PB(a);
    }

    ll x=0, y=0;
    sort(v.begin(), v.end());
    int i=0;
    for(; i<n/2; i++){
        x += (ll)v[i];
    }
    for(; i<n; i++){
        y += (ll)v[i];
    }

    cout << x*x + y*y << endl;

    return 0;
}