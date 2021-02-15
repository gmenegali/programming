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
        vector<int> testCase;
        string s;
        cin >> s;
        for(int j=0; j<(int)s.size(); j++){
            if(j%2 == 0){
                if(s[j] == 'a'){
                    cout << "b";
                }
                else{
                    cout << "a";
                }
            }
            else{
                if(s[j] == 'z'){
                    cout << "y";
                }
                else{
                    cout << "z";
                }
            }
        }
        cout << endl;
 
        t--;
    }
 
    return 0;
}