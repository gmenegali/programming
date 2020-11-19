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
        int n, k, x;
        cin >> n  >> k;
 
        for(int i=0; i<n*k; i++){
            cin >> x;
            testCase.push_back(x);
        }

        sort(testCase.rbegin(), testCase.rend());
        // printVec(testCase);
        ll result = 0;
        int jump = n - (n/2 + (n%2 != 0));
        int current = 0;
        int counter = 0;
        for(int i=0; i<k*n; i++){
            if(current == jump){
                result += (ll) testCase[i];
                current=-1;
                counter++;
                if(counter == k){
                    break;
                }
            }
            current++;
        }
        cout << result << endl;
        t--;
    }
 
    return 0;
}