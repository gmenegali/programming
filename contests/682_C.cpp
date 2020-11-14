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
        int n, x, m;
        cin >> n >> m;

        int first_odd = 0;
        for(int i=0; i<n; i++){
            int odd = first_odd;
            for(int j=0; j<m; j++){
                cin >> x;
                if(odd == 0){
                    if(x%2 == 0){
                        cout << x << " ";
                    }
                    else{
                        cout << x+1 << " ";
                    }
                }
                else{
                    if(x%2 == 0){
                        cout << x+1 << " ";
                    }
                    else{
                        cout << x << " ";
                    }
                }
                odd = (odd+1)%2;
            }
            first_odd = (first_odd+1)%2;
            cout << endl;
        }
 
        t--;
    }
 
    return 0;
}