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
            v.PB(n-i);
        }

        if(n%2 != 0){
            int aux = v[n/2];
            v[n/2] = v[0];
            v[0] = aux;
        }
 
        printVec(v);    
 
        t--;
    }
 
    return 0;
}