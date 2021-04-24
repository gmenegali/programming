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
 
        int n, k, x;
        vi v;
        cin >> n >> k;

        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x <= k){
                v.PB(0);
                k -= x;
                sum += x;
            }
            else if(k>0){
                v.PB(x-k);
                sum += k;
                k = 0;
            }
            else{
                v.PB(x);
            }
        }

        v[n-1] += sum;
        printVec(v);
 
        t--;
    }
 
    return 0;
}