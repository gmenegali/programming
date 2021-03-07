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
        vector<int> a;
        vector<int> b;
        int64_t A, B, n;
        int x;
        cin >> A >> B >>n;

        int max_attack = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            max_attack = max(max_attack, x);
            a.push_back(x);
        }
 
        for(int i=0; i<n; i++){
            cin >> x;
            b.push_back(x);
        }

        int64_t htk;
        bool ok = true;
        B += (int64_t) max_attack-1;
        for(int i=0; i<n; i++){
            htk = (int64_t) (b[i]/A + (b[i]%A != 0)); //Hits to kill
            B -= (int64_t) htk*a[i];
            if(B < 0) ok = false;
        }
        
        if(ok) cout << "YES" << endl;
        else cout << "NO" << endl;
        t--;
    }
 
    return 0;
}
