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
    int n;
 
    cin >> n;
    if(n%2==0){
        cout << (n/2 +1)*(n/2 +1) << endl;
    }
    else{
        cout << 2*(n/2 +1)*(n/2 +2) << endl;
    }
 
    return 0;
}