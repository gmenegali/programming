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
 
        ll n, m, x;
        cin >> n >> m >> x;
        int col = x/n - (x%n == 0);
        int row = x - n*col -1;

        // cout << row << " " << col << endl;;

        cout << (row)*m+col+1 << endl;


 
 
        t--;
    }
 
    return 0;
}