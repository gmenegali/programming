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
        int a, b;
        string s;
        cin >> a >> b >> s;

        int result = 0, zeros_count = 0;
        bool first_one = false;

        for(int i=0; i<(int)s.size(); i++){
            if(!first_one and s[i] == '1'){
                first_one = true;
            }
            else{
                if(first_one and s[i] == '0'){
                    zeros_count++;
                }
                else if(first_one and s[i] == '1'){
                    if(zeros_count != 0){
                        result += min(a, b*zeros_count); 
                    }
                    zeros_count = 0;
                }
            }
        }
        
        if(result != 0){
            result += a;
        }
        else if(first_one){ // result == 0 and there is at least one '1' 
            result += a;
        }
        cout << result << endl;

        t--;
    }
 
    return 0;
}