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
    int t;
 
    cin >> t;
    while(t){
 
        int n;
        string s;
        cin >> n >> s;
        
        char current = 'B';
        for(int i=0; i<n; i++){
            while(s[i] == '?') i++;
            if(i == n) break;
            current = s[i];
            int j = i-1;
            while(j >= 0 and s[j] == '?'){
                if(current == 'B') current = 'R';
                else current = 'B';
                s[j] = current;
                j--;
            }
        }

        for(int i=n-1; i>=0; i--){
            while(s[i] == '?') i--;
            current = s[i];
            int j = i+1;
            while(j < n and s[j] == '?'){
                if(current == 'B') current = 'R';
                else current = 'B';
                s[j] = current;
                j++;
            }
        }

        cout << s << endl;

        t--;
    }
 
    return 0;
}