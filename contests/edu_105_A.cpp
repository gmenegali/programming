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

bool check(string s, int n){
    bool ans = true;

    int open = 0, close = 0;
    for(int i=0; i < n; i++){
        if(s[i] == '(') open++;
        else close++;
        if(close > open){
            ans = false;
            break;
        }
    }

    if(close != open) ans = false;

    return ans;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
        string s;
        cin >> s;
        int n = (int) s.size();
        char A = '-', B = '-', C = '-';
        bool possible = true;

        if(s[0] == 'A') A = '(';
        else if(s[0] == 'B') B = '(';
        else if(s[0] == 'C') C = '(';

        if(s[n-1] == 'A' and s[0] != 'A') A = ')';
        else if(s[n-1] == 'B' and s[0] != 'B') B = ')';
        else if(s[n-1] == 'C' and s[0] != 'C') C = ')';
        else possible = false;


        if(possible){
            string op1 = s;

            for(int i=0; i<n; i++){
                if(op1[i] == 'A') op1[i] = A;
                else if(op1[i] == 'B') op1[i] = B;
                else if(op1[i] == 'C') op1[i] = C;
            }
            string op2 = op1;

            //OP1
            for(int i=0; i<n; i++){
                if(op1[i] == '-') op1[i] = '(';                
            }

            //OP2
            for(int i=0; i<n; i++){
                if(op2[i] == '-') op2[i] = ')';                
            }
            
            if(check(op1, n) or check(op2, n)) possible = true;
            else possible = false;
        }

        if(possible){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }

 
        t--;
    }
 
    return 0;
}