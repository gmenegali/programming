#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define len(s) (int) s.size()
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
    int n;
    string s;
    cin >> n >> s;
    vi sol;

    int wc = 0, bc = 0;
    for(int i=0; i<n; i++){
        if(s[i] == 'B') bc++;
        else wc++;
    }

    int count = 0;
    if(wc == 0 or bc == 0){
        cout << 0 << endl;
    }
    else{
        if(wc % 2 == 0){
            if(s[n-1] == 'W'){
                sol.PB(n-1); //n-2 + 1
                count++;
                s[n-1] = 'B';
                if(s[n-2] == 'B')
                    s[n-2] = 'W';
                else
                    s[n-2] = 'B';
            }
            for(int i=0; i<n-1; i++){
                if(s[i] == 'W'){
                    sol.PB(i+1);
                    count++;
                    if(s[i+1] == 'W'){
                        s[i] = 'B';
                        s[i+1] = 'B';
                    }
                    else{
                        s[i] = 'B';
                        s[i+1] = 'W';
                    }
                }
            }
            cout << count << endl;
            printVec(sol);
        }
        else if(bc % 2 == 0){
            if(s[n-1] == 'B'){
                sol.PB(n-1); //n-2 + 1
                count++;
                s[n-1] = 'W';
                if(s[n-2] == 'W')
                    s[n-2] = 'B';
                else
                    s[n-2] = 'W';

            }
            for(int i=0; i<n-1; i++){
                if(s[i] == 'B'){
                    sol.PB(i+1);
                    count++;
                    if(s[i+1] == 'B'){
                        s[i] = 'W';
                        s[i+1] = 'W';
                    }
                    else{
                        s[i] = 'W';
                        s[i+1] = 'B';
                    }
                }
            }
            cout << count << endl;
            printVec(sol);
        }
        else{
            cout << -1 << endl;
        }
    }

 
    return 0;
}