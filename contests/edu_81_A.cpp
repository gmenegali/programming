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
        string s = "";
        int n;
        cin >> n;

        int ones = n/2;

        for(int i=0; i<n/2; i++){
            s += "1";
        }

        if(n%2 != 0) s[0] = '7';
        
        cout << s << endl;
 
        t--;
    }
 
    return 0;
}   