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

        int n, m;
        char c;

        cin >> n >> m;
        vector<vector<char>> v(n, vector<char> (m,'.'));

        int x, y;
        char target;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> c;
                if(c != '.'){
                    x = i;
                    y = j;
                    target = c;
                }
                v[i][j] = c;
            }
        }

        if((x+y) % 2 != 0){
            if(target == 'R') target = 'W';
            else target = 'R';
        } 

        bool solve = true;
        c = target;
        for(int i=0; i<n; i++){
            target = c;
            for(int j=0; j<m; j++){
                if(v[i][j] != '.' and v[i][j] != target){
                    solve = false;
                    break;
                }
                v[i][j] = target;
                if(target == 'R') target = 'W';
                else target = 'R';
            }
            if(solve == false) break;
            if(c == 'R') c = 'W';
            else c = 'R';
        }

        if(solve){
            cout << "YES" << endl;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    cout << v[i][j];
                }
                cout << endl;
            }       
        }
        else cout << "NO" << endl;
        
        t--;
    }


    return 0;
}