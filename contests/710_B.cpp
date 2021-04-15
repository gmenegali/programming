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
        string s;
        cin >> n >> k >> s;


        vi v;
        for(int i=0; i<n; i++){
            if(s[i] == '*'){
                v.PB(i);
            }
        }
        // cout << k << endl;
        // printVec(v);

        int count = 1;
        int current = v[0];
        for(int i=1; i<(int) v.size(); i++){
            while(i<(int) v.size() and v[i]-current <= k){
                i++;
            }
            i--;
            current = v[i];
            count++;
        }

        cout << count << endl;
        // break;
        t--;
    }
 
    return 0;
}