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
        ll p,a,b,c;
        cin >> p >> a >> b >> c;
        ll first = min(a*(p/a + (p%a != 0)) - p, b*(p/b + (p%b != 0)) - p);
        cout << min(first, c*(p/c + (p%c != 0)) - p)  << endl;
        
        t--;
    }
 
    return 0;
}