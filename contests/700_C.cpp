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
    int n, l=0, m, x, y, z;
    cin >> n;

    
    while(true){
        m = n + (l-n)/2;
        cout << "? " << m << endl;
        cout.flush();
        cin >> y;

        cout << "? " << m+1 << endl;
        cout.flush();
        cin >> z;

        if(y < z){
            n = m;
        }
        else{
            l = m+1;
        }

    }

    return 0;
}