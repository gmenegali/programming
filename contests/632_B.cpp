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
        vi a;
        vi b;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            a.PB(x);
        }
        for(int i=0; i<n; i++){
            cin >> x;
            b.PB(x);
        }

        bool seen_positive = false, seen_negative = false, solve = true;

        for(int i=0; i<n; i++){
            if(a[i] > b[i] and !seen_negative){
                solve = false;
                break;
            }
            if(a[i] < b[i] and !seen_positive){
                solve = false;
                break;
            }
            if(a[i] == 1) seen_positive = true;
            if(a[i] == -1) seen_negative = true;
        }

        if(solve) cout << "YES" << endl;
        else cout << "NO" << endl;
    
        t--;
    }
 
    return 0;
}