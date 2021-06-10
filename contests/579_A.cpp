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
 
        int n, x, target;
        vi v;
        cin >> n;

        int pos = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x == 1) pos = i;
            v.PB(x);
        }

        bool solve = true;
        
        target = 2;
        for(int i=pos+1; i<n; i++){
            if(v[i] != target){
                solve = false;
                break;
            }
            target++;
        }
        if(solve == true){
            target = n;
            for(int i=pos-1; i>=0; i--){
                if(v[i] != target){
                    solve = false;
                    break;
                }
                target--;
            }
        }

        if(solve == false){
            solve = true;
            target = n;
            for(int i=pos+1; i<n; i++){
                if(v[i] != target){
                    solve = false;
                    break;
                }
                target--;
            }
            if(solve == true){
                target = 2;
                for(int i=pos-1; i>=0; i--){
                    if(v[i] != target){
                        solve = false;
                        break;
                    }
                    target++;
                }
            }
            
        }

        if(solve) cout << "YES" << endl;
        else cout << "NO" << endl;

 
 
        t--;
    }
 
    return 0;
}