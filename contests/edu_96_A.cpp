#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
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
        int n;
        cin >> n;

        if(n == 1 or n == 2 or n == 4){
            cout << -1 << endl;
        }
        else{
            if(n%3 == 0){
                cout << n/3 << " " << 0 << " " << 0 << endl;
            }
            else if((n-5)%3 == 0){
                cout << (n-5)/3 << " " << 1 << " " << 0 << endl;
            }
            else{
                cout << (n-7)/3 << " " << 0 << " " << 1 << endl;
            }
        }
 
        t--;
    }
 
    return 0;
}