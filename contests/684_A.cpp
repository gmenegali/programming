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
        int n, c0, c1, h;
        string s;
        cin >> n >> c0 >> c1 >> h >> s;
        
        int zeros=0, ones=0;
        for(int i=0; i<n; i++){
            if(s[i] == '1'){
                ones++;
            }
            else{
                zeros++;
            }
        }

        int result = 0;
        if(c1 > h + c0){
            result = n*c0 + ones*h;
        }
        else if(c0 > h + c1){
            result = n*c1 + zeros*h;
        }
        else{
            result = zeros*c0 + ones*c1;
        }

        cout << result << endl;
 
        t--;
    }
 
    return 0;
}