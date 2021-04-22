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
 
        int n, x;
        vi even;
        vi odd;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            if(x%2 == 0){
                even.PB(x);
            }
            else{
                odd.PB(x);
            }
        }
        
        for(int i=0; i<(int)odd.size(); i++){
            cout << odd[i] << " ";
        }
        for(int i=0; i<(int)even.size(); i++){
            cout << even[i] << " ";
            
        }
        cout << endl;

        t--;
    }
 
    return 0;
}