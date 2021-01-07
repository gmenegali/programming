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
        vector<int> two;
        vector<int> zero;
        int n;
        string s;
        cin >> n >> s;
        
        if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[3] == '0'){
            cout << "YES" << endl;
        }
        else if(s[0] == '2' and s[1] == '0' and s[2] == '2' and s[n-1] == '0'){
            cout << "YES" << endl;
        }
        else if(s[0] == '2' and s[1] == '0' and s[n-2] == '2' and s[n-1] == '0'){
            cout << "YES" << endl;
        }
        else if(s[0] == '2' and s[n-3] == '0' and s[n-2] == '2' and s[n-1] == '0'){
            cout << "YES" << endl;
        }
        else if(s[n-4] == '2' and s[n-3] == '0' and s[n-2] == '2' and s[n-1] == '0'){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
        t--;
    }
 
    return 0;
}