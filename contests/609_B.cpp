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
 
    int n, x, m;
    vi a;
    vi b;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> x;
        a.PB(x);
    }

    for(int i=0; i<n; i++){
        cin >> x;
        b.PB(x);
    }

    vi candidates;
    for(auto item:a){
        candidates.PB((m+b[0] - item)%m);
    }

    sort(candidates.begin(), candidates.end());
    vi v(n,0);
    sort(b.begin(), b.end());
    for(auto candidate:candidates){
        for(int i=0; i<n; i++){
            v[i] = (a[i] + candidate)%m;
        }

        sort(v.begin(), v.end());
        if(v == b){
            cout << candidate << endl;
            break;
        }
        
    }
    return 0;
}