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
 
        ll a, b, x, y, z;
        cin >> a >> b;
        
        ll k, l, m;

        if(b == 1){
            cout << "NO" << endl;
        }
        else{
            x = a * (b-1);
            y = a * (b+1);
            z = x+y;

            cout << "YES" << endl;
            cout << x << " " << y << " " << z << endl;
        }


        t--;
    }
 
    return 0;
}