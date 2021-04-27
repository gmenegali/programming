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
 
        int n, k;
        cin >> n >> k;

        if(k > (n-1)/2){
            cout << -1 << endl;
        }
        else{
            vi ans(n,-1);
            int pos = 1;
            int n_elements = n;
            for(int i=0; i<k; i++){
                ans[pos] = n_elements;
                n_elements--;
                pos += 2;
            }
            for(int i=0; i<n; i++){
                if(ans[i] == -1){
                    ans[i] = n_elements;
                    n_elements--;
                }
            }
            printVec(ans);
        }


 
 
        t--;
    }
 
    return 0;
}