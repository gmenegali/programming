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
    int t;
 
    cin >> t;
    while(t){
 
        int n, x, k;
        vi v;
        cin >> n >> k;

        ll result = 1;
        for(int i=0; i<k; i++){
            result *= n % (1000000000 + 7);
            result %= (1000000000 + 7);
        }

        cout << result << endl;
 
 
        t--;
    }
 
    return 0;
}