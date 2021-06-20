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

    int n, x;
    vi v;
    cin >> n;

    int odd =0, even = 0;
    for(int i=0; i<n; i++){
        cin >> x;
        if(x % 2 == 0) even++;
        else odd++;
        v.PB(x);
    }

    cout << min(odd, even) << endl;

 
    return 0;
}