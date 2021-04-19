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

        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        int ans = -1;
        for(int i=1; i<n-1; i++){
            if(v[i] != v[i-1] and v[i] != v[i+1]) ans = i+1;
        }
        if(ans == -1){
            if(v[0] != v[1]){
                ans = 1;
            }
            else{
                ans = n;
            }
        }
 
        cout << ans << endl;
        
        t--;
    }
 
    return 0;
}