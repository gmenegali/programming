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
        vector<int> testCase;
        int n, x, m;
        cin >> n >> m;

        bool has_zero = false;
        int total = 0, minimum = INT_MAX, negatives = 0;

        for(int i=0; i<n*m; i++){
            cin >> x;
            total += abs(x);
            minimum = min(minimum, abs(x));
            if(x == 0){
                has_zero = true;
            }
            if(x < 0){
                negatives++;
            }
        }
        if(has_zero or negatives % 2 == 0){
            cout << total << endl;
        }
        else{
            cout << total - 2*minimum << endl;
        }
 
        t--;
    }
 
    return 0;
}