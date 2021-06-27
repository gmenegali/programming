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
 
        int n, x;
        vi v;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        int result = 0;
        for(int i=0; i<n; i++){
            int j = i + v[i] - ((2*(i+1)) % v[i]);
            for(; j<n; j+=v[i]){
                if((ll)(i+j+2) == (ll) v[i]* (ll) v[j]){
                    result++;
                }
            }
        }
 
        cout << result << endl;
 
        t--;
    }
 
    return 0;
}