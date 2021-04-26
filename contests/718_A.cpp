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
 
        ll n, aux=2050;
        cin >> n;

        while(aux <= n) aux *= 10;
        if(aux != 2050) aux /= 10;

        int ans = 0;
        while(n != 0){
            if(n >= aux){
                n -= aux;
                ans++;
            }
            else{
                while(aux > n) aux /= 10;
                if(aux < 2050) break;
            }

        }

        if(n == 0){
            cout << ans << endl;
        }
        else{
            cout << -1 << endl;
        }

        t--;
    }
 
    return 0;
}