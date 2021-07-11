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

    int n, k;
    string s;
    cin >> n >> k >> s;

    if(n == 1 and k>0) s = "0";
    else{
        for(int i=0; i<n; i++){
            if(i == 0){
                if(s[i] != '1' and s[i] != '0' and k>0){
                    s[i] = '1';
                    k--;
                }
            }
            else{
                if(k>0 and s[i] != '0'){
                    s[i] = '0';
                    k--;
                }
            }
        }
    }


    cout << s << endl;
 
    return 0;
}
