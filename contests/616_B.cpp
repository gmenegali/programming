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

        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        target = 0;
        int inc = -1;
        for(int i=0; i<n; i++){
            if(v[i] < target){
                break;
            }
            inc = i;
            target++;
        }

        target = 0;
        int dec = -1;
        for(int i=n-1; i>=0; i--){
            if(v[i] < target){
                break;
            }
            dec = i;
            target++;
        }

        // printVec(v);
        // cout << "inc: " << inc << endl << "dec: " << dec << endl;
       

        if(dec == 0 or inc == n-1 or inc >= dec)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;


        t--;
    }
 
    return 0;
}