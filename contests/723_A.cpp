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
 
        int n, x;
        vi v;
        vi ans;
        cin >> n;

        for(int i=0; i<2*n; i++){
            cin >> x;
            v.PB(x);
        }

        while(true){
            bool ok = true;

            for(int i=0; i<2*n - 2; i++){
                if((v[i] + v[i+2])%2 == 0 and v[i+1] == (v[i] + v[i+2])/2){
                    int aux = v[i+1];
                    v[i+1] = v[i+2];
                    v[i+2] = aux;
                    ok = false;
                }
            }
            
            if((v[2*n-2] + v[0])%2 == 0 and v[2*n-1] == (v[2*n-2] + v[0])/2){
                int aux = v[2*n-1];
                v[2*n-1] = v[0];
                v[0] = aux;
                ok = false;
            }

            if((v[2*n-1] + v[1])%2 == 0 and v[0] == (v[2*n-1] + v[1])/2){
                int aux = v[0];
                v[0] = v[1];
                v[1] = aux;
                ok = false;
            }

            if(ok) break;
        }
        
        



        printVec(v);


 
        t--;
    }
 
    return 0;
}