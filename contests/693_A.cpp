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
 
        int w,h,n;
        ll result=1;
        cin >> w >> h >> n;
        while(h%2 == 0){
            result *= 2;
            h /=2;
        }
        while(w%2 == 0){
            result *= 2;
            w /= 2;
        }
        if(result >= n) cout << "YES" << endl;
        else cout << "NO" << endl;


        t--;
    }
 
    return 0;
}