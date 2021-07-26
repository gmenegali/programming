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
 
        ll a,b,diff;
        cin >> a >> b;

        diff = max(a,b) - min(a,b);
    
        if(diff == 0) cout << "0 0" << endl;
        else{
            ll opt1 = (a/diff) * diff;
            ll opt2 = opt1+diff;

            cout << diff << " " << min(a-opt1,opt2-a) << endl;
        }

        t--;
    }
 
    return 0;
}
