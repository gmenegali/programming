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
 
        int n, x;
        vi v;
        cin >> n;

        bool ordered = true;
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
            if(ordered and i>0 and v[i] < v[i-1]) ordered = false;
        }
        if(ordered) cout << 0 << endl;
        else if(v[0] == n and v[n-1] == 1) cout << 3 << endl;
        else if(v[0] == 1 or v[n-1] == n) cout << 1 << endl;
        else cout << 2 << endl;
 
        t--;
    }
 
    return 0;
}