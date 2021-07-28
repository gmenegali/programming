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
 
        int n, c1,c2;
        cin >> n;

        c1 = n/3;
        c2 = c1;

        int rest = n-3*c1;
        if(rest == 1) c1++; 
        else if(rest == 2) c2++;

        cout << c1 << " " << c2 << endl;

 
        t--;
    }
 
    return 0;
}