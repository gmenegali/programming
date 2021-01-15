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
        string s;
        cin >> s;

        int open, close;
        for(int i=0; i<(int)s.size(); i++){
            if(s[i] == '(')
                open = i;
            if(s[i] == ')')
                close = i;
        }

        if((int) s.size() % 2 == 0){
            if(open<close)
                cout << "YES" << endl;
            else{
                if(open != (int)s.size()-1 and close != 0){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
        else{
            cout << "NO" << endl;
        }




 
        t--;
    }
 
    return 0;
}