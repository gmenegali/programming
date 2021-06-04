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
 
        int n, d;
        cin >> n >> d;
 
        if(d <= n){
            cout << "YES" << endl;
        }
        else{
            int x = n/2;
            bool solve = false;
            while(x != 0){
                if(x+(d/(x+1)) + (d%(x+1) != 0) <= n){
                    solve = true;
                    break;
                }
                x /= 2;
            }

            if(solve){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
 
 
        t--;
    }
 
    return 0;
}