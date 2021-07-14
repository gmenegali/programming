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
 
    int n, l, r;
    cin >> n >> l >> r;

    ll min = 0, max = 0;

    // min = (n-l+1);
    // for(int i=1; i<(l); i++) min += 2*i;


    int count = 0;
    int factor = 2;
    for(int i=1; i<r; i++){
        max += factor;
        count++;
        factor *= 2;
    }
    max += 1;
    factor /= 2;
    for(int i=0; i<(n-r); i++){
        max += factor;
    }

    count = 0;
    factor = 2;
    for(int i=1; i<l; i++){
        min += factor;
        count++;
        factor *= 2;
    }
    min += 1;
    min += (n-l);



    cout << min  << " " << max << endl;
 
    return 0;
}