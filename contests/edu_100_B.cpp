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
        int n, x;
        cin >> n;
        ll first=0, second=0;
 
        for(int i=0; i<n; i++){
            cin >> x;
            if(i%2==0){
                first+=x;
            }
            else{
                second+=x;
            }
            testCase.push_back(x);
        }
        if(first>second){
            for(int i=0; i<n; i++){
                if(i%2 == 1){
                    cout << 1 << " ";
                }
                else{
                    cout << testCase[i] << " ";
                }
            }
        }
        else{
            for(int i=0; i<n; i++){
                if(i%2 == 1){
                    cout << testCase[i] << " ";
                }
                else{
                    cout << 1 << " ";
                }
            }
        }
        cout << endl;
 
        t--;
    }
 
    return 0;
}