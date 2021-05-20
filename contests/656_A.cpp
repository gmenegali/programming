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
 
        int n = 3, x, maxi = 0, diff = -1;
        vi v;
 
        for(int i=0; i<n; i++){
            cin >> x;
            maxi = max(maxi, x);
            v.PB(x);
        }

        int count = 0;
        for(int i=0; i<n; i++){
            if(v[i] == maxi){
                count++;
            }
            else{
                diff = v[i];
            }
        }

        if(count >= 2){
            cout << "YES" << endl;
            if(diff == -1){
                cout << maxi << " " << maxi << " " << maxi << endl;
            }
            else{
                cout << diff << " " << diff << " " << maxi << endl;
            }
        }
        else{
            cout << "NO" << endl;
        }
 
        t--;
    }
 
    return 0;
}