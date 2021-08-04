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
 
        ll n, x;
        vector<ll> v;
        cin >> n;


        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        ll mini, maxi, result=0;
        for(int i=0; i<n-1; i++){
            mini = v[i];
            maxi = v[i+1];
            result = max(result, mini*maxi);
        }

        cout << result << endl;
 
        t--;
    }
 
    return 0;
}