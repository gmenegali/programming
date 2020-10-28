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
    // int t;
 
    // cin >> t;
    // while(t){
    //     ll l, r;
    //     cin >> l >> r;

    //     if(r < 2*l){
    //         cout << "YES" << endl;
    //     }
    //     else{
    //         cout << "NO" << endl;
    //     }
 
    //     t--;
    // }

    int l = 1, r = 2;

    for(int a=2; a<=2*r; a++){
        bool t = true;
        for(int i=l; i<=r; i++){
            if(i%a < a/2){
                t = false;
                break;
            }
        }

        if(t){
            cout << a << " " << "OK" << endl;
        }
        else{
            cout << a << " " << "FAIL" << endl;
        }
    }
 
    return 0;
}