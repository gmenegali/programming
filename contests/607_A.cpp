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
        string s;
        cin >> s;
        int n = (int) s.size() - 1;
        if(s[n] == 'o') cout << "FILIPINO" << endl;
        if(s[n] == 'u') cout << "JAPANESE" << endl;
        if(s[n] == 'a') cout << "KOREAN" << endl;
                        
 
        t--;
    }
 
    return 0;
}