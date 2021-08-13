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
 
        int a,b,c;
        cin >> a >> b >> c;
        int diff = abs(a-b);
        int total = 2*diff;

        if(a>total or b>total) cout << -1 << endl;
        else if(c <= diff) cout << c+diff << endl;
        else if(c <= total) cout << c-diff << endl;
        else cout << -1 << endl;


        t--;
    }
 
    return 0;
}