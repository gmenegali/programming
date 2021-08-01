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
 
        ll n, x;
        vector<ll> v;
        cin >> n;

        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            sum += x;
            v.PB(x);
        }
        sort(v.begin(), v.end());

        double result = INT_MIN;

        ll current_sum = 0;
        for(int i=0; i<n-1; i++){
            current_sum += v[i];
            double candidate = (double) current_sum/(double) (i+1) + (double) (sum-current_sum)/(double) (n-i-1); 
            result = max(result,candidate);

        }

        printf("%.8f\n", result);
 
        t--;
    }
 
    return 0;
}