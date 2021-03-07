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

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
int main(){

    vector<ll> a;
    vector<ll> b;
    ll x;
    int n, m;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> x;
        a.push_back(x);
    }

    for(int i=0; i<m; i++){
        cin >> x;
        b.push_back(x);
    }

    ll gcd_base=0;
    for(int i=1; i<n; i++){
        gcd_base = gcd(abs(a[i]-a[0]), gcd_base);
    }

    ll result;
    for(int j=0; j<m; j++){ 
        result = gcd(a[0]+b[j], gcd_base);
        cout << result << " ";
    }

    cout << endl;

    return 0;
}