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
        string b, a="";
        cin >> n >> b;

        int last = -1;
        for(int i=0; i<n; i++){
            if(last == -1){
                a.PB('1');
                if(b[i] == '1')
                    last = 2;
                else
                    last = 1;
            }
            else if(last == 2){
                if(b[i] == '1'){
                    last = 1;
                    a.PB('0');
                }
                else{
                    last = 1;
                    a.PB('1');
                }
            }
            else if(last == 1){
                if(b[i] == '1'){
                    last = 2;
                    a.PB('1');
                }
                else{
                    last = 0;
                    a.PB('0');
                }
            }
            else{
                if(b[i] == '1'){
                    last = 2;
                    a.PB('1');
                }
                else{
                    last = 1;
                    a.PB('1');
                }
            }
        }

        cout << a << endl;
        t--;
    }
 
    return 0;
}