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
    string s;
    cin >> s;

    int n = (int) s.size();
    int middle;
    if(n%2 == 0) middle = n/2 - 1;
    else middle = n/2;

    int diff = 0;
    for(int i=0; i<=middle; i++){
        if(s[i] != s[n-1-i]) diff++;
    }
    
    if(diff == 1) cout << "YES" << endl;
    else{
        if(diff == 0 and n%2 != 0) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


    return 0;
}