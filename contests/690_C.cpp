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
        cout << v[i];
    }
    cout << endl;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
        vector<int> testCase;
        int n, current = 9;
        cin >> n;

        if(n<=45){
            while(n>0){
                if(n >= current){
                    testCase.PB(current);
                    n -= current;
                }
                else{
                    testCase.PB(n);
                    n = 0;
                }
                current--;
            }

            sort(testCase.begin(), testCase.end());
            printVec(testCase);
        }
        else{
            cout << -1 << endl;
        }

        t--;
    }
 
    return 0;
}   