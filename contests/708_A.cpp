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
        vi v1, v2;
        set<int> h;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            if(h.find(x) == h.end()){
                v1.PB(x);
                h.insert(x);
            }
            else{
                v2.PB(x);
            }
        }
        sort(v1.begin(), v1.end());
        for(int i=0; i < (int) v1.size(); i++){
            cout << v1[i] << ' ';
        }
        for(int i=0; i < (int) v2.size(); i++){
            cout << v2[i] << ' ';
        }
        cout << endl;
        t--;
    }
 
    return 0;
}