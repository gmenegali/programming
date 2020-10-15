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

        cout << 2 << endl;
        if(n == 2){
            cout << 2 << " " << 1 << endl;
        }
        else{
            cout << n << " " << n-2 << endl;
            int middle  = n-1;
            cout << middle << " " << middle << endl;
            n-=3;
            while(n >= 1){
                cout << n << " " << middle << endl;
                middle--;;
                n--;
            }
        }

 
        t--;
    }
 
    return 0;
}