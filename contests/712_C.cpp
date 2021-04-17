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
        cin >> n >> s;
        
        bool possible = true;
        if(s[0] != '1' or s[(int) s.size()-1] != '1') possible = false;
        int zeros = 0;
        for(int i=0; i<n; i++){
            if(s[i]=='0') zeros++;
        }
        if(zeros %2 != 0) possible = false;
        int ones = n-zeros;
        int ones_passed = 1;
        int turn = 0;

        if(possible){
            cout << "YES" << endl;
            string ans = "(";
            string ans2 = "(";

            for(int i=1; i<n; i++){
                if(s[i] == '1'){
                    if(ones_passed < ones/2 ){
                        ans.PB('(');
                        ans2.PB('(');
                    }
                    else{
                        ans.PB(')');
                        ans2.PB(')');
                    }
                    ones_passed++;
                }
                else{
                    if(turn == 0){
                        ans.PB('(');
                        ans2.PB(')');
                        turn = 1;
                    }
                    else{
                        ans.PB(')');
                        ans2.PB('(');
                        turn = 0;
                    }
                }
            }   
            cout << ans << endl << ans2 << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
        t--;
    }
 
    return 0;
}