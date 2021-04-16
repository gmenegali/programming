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
        int n = (int) s.size();

        int j = 0;
        int i = n-1;
        bool palin = false;
        while(i>=j){
            if(s[i] != s[j]){
                palin = true;
                s.insert(s.begin() + i, 'a');
                break;
            }
            else{
                if(s[j] != 'a'){
                    palin = true;
                    s.insert(s.begin() + j, 'a');
                    break;
                }
            }
            j++;
            i--;
        }
        if(palin){
            cout << "YES" << endl << s << endl;
        }
        else{
            cout << "NO" << endl;
        }


        t--;
    }
 
    return 0;
}