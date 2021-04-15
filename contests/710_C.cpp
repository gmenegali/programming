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
        string a, b, c;
        cin >> a >> b;

        vector<vi> v((int) a.size(), vi((int) b.size(), 0));
        
        for(int i=0; i<(int)a.size(); i++){
            for(int j=0; j<(int)b.size(); j++){
                if(a[i] == b[j]){
                    if(i>0 and j>0){
                        v[i][j] = v[i-1][j-1] + 1;
                    }
                    else{
                        v[i][j] = 1;
                    }
                }
            }
        }
        
        int result = 0;
        for(auto x : v){
            for(auto y : x){
                result = max(result, y);
            }
            
        }
        
        cout << (int) a.size() + (int) b.size() - 2 * result << endl;
        t--;
    }
 
    return 0;
}