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

    if(n > 26){
        cout << -1 << endl;
    }
    else{
        int count = 0;
        unordered_set<int> hash;
        for(int i=0; i<n; i++){
            if(hash.find(s[i]) != hash.end()){
                count++;
            }
            else hash.insert(s[i]);
        }
        cout << count << endl;
    }


 
    return 0;
}