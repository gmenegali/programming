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
    int n;
    string s;
    cin >> n >> s;

    int count = 0;
    for(int i=0; i<n; i+=2){
        if(s[i] == 'a' and s[i+1] == 'a'){
            s[i] = 'b';
            count++;
        }
        if(s[i] == 'b' and s[i+1] == 'b'){
            s[i] = 'a';
            count++;
        }
    }
    cout << count << endl;
    cout << s << endl;

 
    return 0;
}   