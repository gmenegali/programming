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
 
        ll n, x, y, mini=0, maxi=0;
        vi v;
        cin >> n >> x;
 
        for(int i=0; i<n; i++){
            cin >> y;
            mini += y;
            maxi += (y/x + (y % x != 0));
            v.PB(y);
        }

        cout << (mini/x + (mini % x != 0)) << " " << maxi << endl;
 
        t--;
    }
 
    return 0;
}