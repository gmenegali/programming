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

bool solve(int n, int a, int b){
    if(a == 1){
        if((n-1)%b == 0) return true;
        else return false;
    }

    int target_mod = n%b;
    ll first = 1;
    while(first % b != target_mod){
        first *= a;
        if(first > 2e9) break;
    }
    if(first <= n) return true;
    else return false;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, a, b;
        cin >> n >> a >> b;

        if(solve(n,a,b)) cout << "YES" << endl;
        else cout << "NO" << endl;
        
        t--;
    }
 
    return 0;
}