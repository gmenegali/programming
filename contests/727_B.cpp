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
 
    int n,q,l,r;
    string s;

    cin >> n >> q >> s;

    vi v;
    v.PB(s[0]-96);
    for(int i=1; i<n; i++){
        v.PB(s[i]-96+v[i-1]);
    }

    for(int i=0; i<q; i++){
        cin >> l >> r;
        int result = v[r-1];
        if(l != 1) result -= v[l-2];
        cout << result << endl; 
    }



 
    return 0;
}