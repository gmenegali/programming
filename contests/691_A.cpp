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
        vector<int> r;
        vector<int> b;
        int n;
        string x, y;
        cin >> n >> x >> y;
 
        for(int i=0; i<n; i++){
            r.push_back((int) (x[i]-'0'));
        }
 
        for(int i=0; i<n; i++){
            b.push_back((int) (y[i]-'0'));
        }

        int r_wins = 0, b_wins=0;
        for(int i=0; i<n; i++){
            if(r[i] > b[i])
                r_wins++;
            if(b[i] > r[i])
                b_wins++;
        }

        if(r_wins > b_wins){
            cout << "RED" << endl;
        }
        else if(r_wins == b_wins){
            cout << "EQUAL" << endl;
        }
        else{
            cout << "BLUE" << endl;
        }
 
        t--;
    }
 
    return 0;
}