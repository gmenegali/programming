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
 
        int open1 =0, open2=0, result=0;
        for(int i=0; i<(int)s.size(); i++){
            if(s[i] == '('){
                open1++;
            }
            if(s[i] == '['){
                open2++;
            }
            if(s[i] == ')' and open1){
                open1--;
                result++;
            }
            if(s[i] == ']' and open2){
                open2--;
                result++;
            }
        }


        cout << result << endl;
        t--;
    }
 
    return 0;
}