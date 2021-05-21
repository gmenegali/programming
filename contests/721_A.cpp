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
 
        int n, n_copy, p=0;
        cin >> n;
        n_copy = n;
        // if(n%2 == 0) result = 0;
        // else result = 1;

        while(n != 0){
            n /= 2;
            p++;
        }
        p--;

        int result = 1;
        while(p){
            result *=2;
            p--;
        }



        cout << n_copy - (n_copy - result + 1) << endl;
 
        t--;
    }
 
    return 0;
}