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
 
        int n, x, k;
        vi v;
        cin >> n >> k;

        ll sum = 0;
        bool possible = true;
        for(int i=0; i<n; i++){
            cin >> x;
            sum += x;
            if(sum != k){
                v.PB(x);
            }
            else{
                if(i != n-1){
                    int x2;
                    cin >> x2;
                    v.PB(x2);
                    v.PB(x);
                    sum += x2;
                    i++;
                }
                else {
                    possible = false;
                }
            }

        }
        if(sum == k){
            possible = false;
        }

        if(possible){
            cout << "YES" << endl;
            printVec(v);
        }
        else{
            cout << "NO" << endl;
        }
 
        t--;
    }
 
    return 0;
}