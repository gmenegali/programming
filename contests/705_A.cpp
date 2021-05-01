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
 
        int n, k;
        cin >> n >> k;
        
        vi v;
        
        for(int i=n; i>k; i--){
            v.PB(i);
        }

        int limit;
        if(k%2 == 0){
            limit = k/2;
        }
        else{
            limit = 1+k/2;
        }
        for(int i=k-1; i>=limit; i--){
            v.PB(i);
        }

        int len = (int) v.size();
        if(len == 0){
            cout << 0 << endl;
        }
        else{
            cout << len << endl;
            printVec(v);
        }
 
        t--;
    }
 
    return 0;
}