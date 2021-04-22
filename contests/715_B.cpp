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

bool solve(string s, int n){
    vi m;
    vi t;

    for(int i=0; i<n; i++){
        if(s[i] == 'T'){
            t.PB(i);
        }
        else{
            m.PB(i);
        }
    }
    int m_len = (int) m.size(); 
    int t_len = (int) t.size(); 

    if(m_len*2 != t_len){
        return false;
    }

    for(int i=0; i<m_len; i++){
        if(m[i] < t[i]) return false;
        if(m[i] > t[i+m_len]) return false;
    }

    return true;
}

 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n;
        string s;
        cin >> n >> s;

        if(solve(s, n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
 
        t--;
    }
    
    return 0;
}