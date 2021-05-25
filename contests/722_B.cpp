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
 
        int n, x;
        vi v;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        sort(v.begin(), v.end());

        int count = 1;
        int min_diff = 1e9+1;
        for(int i=1; i<n; i++){
            min_diff = min(min_diff, abs(v[i-1] - v[i]));
            if(abs(v[0] - v[i]) >= v[i] and abs(v[i-1] - v[i]) >= v[i] and v[i] <= min_diff) count++;
        }
        
        cout << count << endl;

        t--;
    }
 
    return 0;
}