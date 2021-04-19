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
        cin >> n;
        vector<string> m;
        string s;

        int x1=-1,x2=-1,y1=-1,y2=-1;
        for(int i=0; i<n; i++){
            cin >> s;
            m.PB(s);
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(m[i][j] == '*'){
                    if(x1 == -1){
                        x1 = i;
                        y1 = j;
                    }
                    else{
                        x2 = i;
                        y2 = j;
                    }
                }
            }
        }

        if(x1 == x2){
            if(x1 != n-1){
                m[x1+1][y1] = '*';
                m[x1+1][y2] = '*';
            }
            else{
                m[x1-1][y1] = '*';
                m[x1-1][y2] = '*';
            }
        }
        else{
            if(y1 == y2){
                if(y1 != n-1){
                    m[x1][y1+1] = '*';
                    m[x2][y1+1] = '*';
                }
                else{
                    m[x1][y1-1] = '*';
                    m[x2][y1-1] = '*';
                }
            }
            else{
                    m[x1][y2] = '*';
                    m[x2][y1] = '*';                
            }
        }

        

        for(auto line : m){
            cout << line << endl;
        }


 
        t--;
    }
 
    return 0;
}