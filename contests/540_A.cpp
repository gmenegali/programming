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
        ll n, result = 0;
        float a,b,cmp;
        

        cin >> n >> a >> b;
        cmp = b/2;

        if(cmp >= a) result = n* (ll)a;
        else{
            result = (n/2)*(ll)b + (ll)a*(n%2 != 0);
        }

        cout << result << endl;
        t--;
    }
 
    return 0;
}