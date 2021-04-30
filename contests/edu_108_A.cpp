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
 
        int r, b, d;
        cin >> r >> b >> d;

        int packets = min(r,b);
        int n_to_distribute = max(r,b)-packets;
        int max_to_each = n_to_distribute/packets + (n_to_distribute % packets != 0);

        if(max_to_each > d){
            cout << "NO" << endl;
        } 
        else{
            cout << "YES" << endl;
        }



        t--;
    }
 
    return 0;
}