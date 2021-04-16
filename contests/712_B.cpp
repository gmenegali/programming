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
 
        int n, z1=0, z2=0, o1=0, o2=0;
        string s1, s2;
        cin >> n >> s1 >> s2;

        bool solve = true;
        bool equal = true;
        bool inverted = true;
        for(int i=0; i<n; i++){
            if(s1[i] == '1'){
                o1++;
            }
            else{
                z1++;
            }
            if(s2[i] == '1'){
                o2++;
            }
            else{
                z2++;
            }

            if(equal and s1[i] != s2[i]) equal = false;
            if(inverted and s1[i] == s2[i]) inverted = false;

            if(s1[i] != s2[i]) solve = false;

            if(o1 == z1){
                if(!equal and !inverted){
                    solve = false;
                    break;
                }
                else{
                    equal = true;
                    inverted = true;
                    solve = true;
                }
            }
        }

        if(solve){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
 
        t--;
    }
 
    return 0;
}