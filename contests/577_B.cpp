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
 
    ll n, x, sum=0, h=0;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        sum += x;
        h = max(h,x);
    }

 
    if(sum % 2 == 0 and h <= (sum-h)){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
 

 
    return 0;
}