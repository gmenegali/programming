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
 
        int n, l, r, x;
        vi v;
        cin >> n >> l >> r;
 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }
        sort(v.begin(), v.end());
        printVec(v);
        int result = 0;
        for(int i=0; i<n-1; i++){
            int a = upper_bound(v.begin()+i+1, v.end(), r-v[i]) - v.begin();
            a = min((int)v.size()-1, a);
            int b = lower_bound(v.begin()+i+1, v.end(), l-v[i]) - v.begin();
            b = max(i+1, b);
            cout << a << " " << b << endl;
            if(a>=b) result += 1 + a - b;
            
        }

        cout << result << endl;
 
        t--;
    }
 
    return 0;
}