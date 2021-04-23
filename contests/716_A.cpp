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
        cin >> n;

        bool ans = false;
        for(int i=0; i<n; i++){
            cin >> x;
            int test = (int) sqrt(x);
            if(test*test != x){
                ans = true;
            }
        }

        if(ans){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;   
        }
 
 
        t--;
    }
 
    return 0;
}