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
 
        int n, zeros=0;
        string s;
        cin >> n >> s;

        for(int i=0; i<n; i++){
            if(s[i] == '0') zeros++;
        }

        if(zeros == 0){
            cout << "DRAW" << endl;
        }
        else if(zeros % 2 == 0){
            cout << "BOB" << endl;
        }
        else{
            if(zeros > 1)
                cout << "ALICE" << endl;
            else
                cout << "BOB" << endl;

        }
        

        t--;
    }
 
    return 0;
}