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
        string s;
        cin >> s;
        n = (int) s.size();

        int ans = 0;
        bool started = false;
        for(int i=0; i<n; i++){
            if(s[i] == '0' and started == true){
                int counter = 0;
                while(i < n and s[i] == '0'){
                    counter++;
                    i++;
                }
                if(i != n) ans += counter;
            }
            else if(started == false and s[i] == '1'){
                started = true;
            }
        }
// 1111000
        cout << ans << endl;
 
        t--;
    }
 
    return 0;
}