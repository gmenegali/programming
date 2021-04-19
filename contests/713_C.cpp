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
 
        int a,b;
        string s;
        cin >> a >> b >> s;
        int n = (int) s.size();

        int ones = 0, zeros = 0;
        for(int i=0; i<n; i++){
            if(s[i] == '1') ones++;
            else if(s[i] == '0') zeros++;
            else{
                if(s[n-i-1] == '1'){
                    s[i] = '1';
                    ones++;
                }
                else if(s[n-i-1] == '0'){
                    s[i] = '0';
                    zeros++;
                }
            }
        }
        
        int i=0, j=n-1;
        bool ok = true;


        while(i <= j){
            if(s[i]=='?' or s[j] == '?'){
                if(s[i] == '1' or s[j] == '1'){
                    s[i] = '1';
                    s[j] = '1';
                    ones++;
                }
                else if(s[i] == '0' or s[j] == '0'){
                    s[i] = '0';
                    s[j] = '0';
                    zeros++;
                }
                else if(i==j){
                    if(a-zeros > 0){
                        s[i] = '0';
                        zeros++;
                    }
                    else if(b-ones > 0){
                        s[i] = '1';
                        ones++;
                    }
                }
                else if(a-zeros > 1){
                    s[i] = '0';
                    s[j] = '0';
                    zeros += 2;
                }
                else if(b-ones > 1){
                    s[i] = '1';
                    s[j] = '1';
                    ones += 2;
                }
            }

            else if(s[i] != s[j]){
                ok = false;
                break;
            }
            i++;
            j--;
        }

        if(a != zeros or b != ones) ok = false;
        if(ok){
            cout << s << endl;
        }
        else{
            cout << -1 << endl;
        }
 
        t--;
    }
 
    return 0;
}