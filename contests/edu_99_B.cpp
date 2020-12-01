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
    vector<int> testCase;
    testCase.PB(0);
    int i=1;
    while(testCase[(int) testCase.size() -1]<=1000000){
        testCase.PB(testCase[(int) testCase.size() -1] + i);
        i++;
    }
    // printVec(testCase);
 
    cin >> t;
    while(t){
        int n;
        cin >> n;
        for(int i=0; i< (int) testCase.size(); i++){
            if(n <= testCase[i]){
                int extra = testCase[i]-n;
                // for(int i=1; i < (int) testCase.size(); i++){
                //     extra += -1-testCase[i];
                // }
                if(extra > 1){
                    cout << i << endl;
                }
                else{
                    cout << i+extra << endl;
                }
                // cout << n << " " << i << " " << " " << extra << endl;
                break;
            }
        }
 
        t--;
    }
 
    return 0;
}