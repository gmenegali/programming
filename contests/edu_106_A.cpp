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
 
        int n, k1, k2, w, b;
        cin >> n >> k1 >> k2 >> w >> b;

        int white_up = min(k1,k2);
        int white_down = (max(k1,k2) - white_up)/2;
        int black_up = min(n-k1,n-k2);
        int black_down = (max(n-k1,n-k2) - black_up)/2;

        if(w <= white_up+white_down and b <= black_down+black_up){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

 
        t--;
    }
 
    return 0;
}