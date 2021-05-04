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
 
        int n, x, d;
        cin >> n >> d;
        vi v;

        int min1 = 101, min2 = 101, min1_pos=-1;
        bool higher = false;
        for(int i=0; i<n; i++){
            cin >> x;
            if(higher == false and x>d){
                higher = true;
            }
            if(x < min1){
                min1 = x;
                min1_pos = i;
            }
            v.PB(x);
        }

        for(int i=0; i<n; i++){
            if(i == min1_pos) continue;
            if(v[i] < min2) min2 = v[i];
        }

        // cout << min1 << " " << min2 << endl;
        if(higher == false) cout << "YES" << endl;
        else if(min1 + min2 <= d) cout << "YES" << endl;
        else cout << "NO" << endl;

        t--;
    }
 
    return 0;
}