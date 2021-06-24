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

ll sum_pa(ll x){
    return (ll) (x+1)*x/2;
}
 
int main(){
    int k;
 
    cin >> k;
    while(k){
 
        ll n, x, f;
        cin >> n >> x >> f;

        if(x > f) cout << 0 << endl;
        else if(x==f) cout << n-1 << endl;
        else{
            ll result = 0;
            int magnitude = min(1 + f/x, n);
            result += (magnitude - 1) * (n-magnitude); 
            result += sum_pa(magnitude-1);
            cout << result << endl;
    
        }


        k--;
    }
 
    return 0;
}