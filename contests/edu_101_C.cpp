#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i < b; i++)
 
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
        vector<int> testCase;
        int n, k, x;
        cin >> n >> k;

        for(int i=0; i<n; i++){
            cin >> x;
            testCase.push_back(x);
        }
        // printVec(testCase);
        int base_min = testCase[0];
        int base_max = testCase[0];
        // cout << "[" << base_min << ", " << base_max << "] ";
        bool ok = true;
        for(int i=1; i<n; i++){
            base_min = max(base_min - (k-1), testCase[i]);
            base_max = min(base_max+(k-1), testCase[i]+(k-1));
            if(base_min > base_max){
                ok = false;
                break;
            }
            // cout << "[" << base_min << ", " << base_max << "] ";
        }
        // cout << endl;

        if(testCase[n-1]>base_max or testCase[n-1] < base_min){
            ok = false;
        }

        if(ok) cout << "YES" << endl; else cout << "NO" << endl;
 
        t--;
    }
 
    return 0;
}