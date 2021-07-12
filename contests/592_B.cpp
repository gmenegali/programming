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
 
        int n, x;
        string s;
        cin >> n >> s;

        vi pos;
        for(int i=0; i<n; i++){
            if(s[i] == '1') pos.PB(i);
        }
        int m = (int) pos.size(); 

        if(m == 0) cout << n << endl;
        else{
            int opt1 = pos[m-1] + 1 + max(pos[m-1] + 1, n-(pos[m-1] + 1)); 
            int opt2 = n - pos[0] + max(n - pos[0], n-(n - pos[0]));
            cout << max(opt1, opt2) << endl; 
        }
 
        t--;
    }
 
    return 0;
}