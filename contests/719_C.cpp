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
 
        int n;
        cin >> n;
        if(n == 2){
            cout << -1 << endl;;
            t--;
            continue;
        }
        vector<vi> v(n, vector<int>(n));


        int count = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                v[i][j] = count;
                count++;
            }
        }

        for(int i=1; i<n; i+=2){
            int memo = v[0][i];
            for(int j=0; j<n-1; j++){
                v[j][i] = v[j+1][i];
            }
            v[n-1][i] = memo;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                cout << v[i][j] << " ";
            }
            cout << endl;
        }
 
        t--;
    }
 
    return 0;
}
