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
        vector<int> testCase;
        ll x1, x2, y1, y2, dif1, dif2;
        cin >> x1 >> y1 >> x2 >> y2;

        dif1 = abs(x1-x2);
        dif2 = abs(y1-y2);
        
        if(dif1 == 0 or dif2 == 0){
            cout << dif1 + dif2 << endl;
        }
        else{
            cout << dif1 + dif2 + 2 << endl;
        }


        t--;
    }
 
    return 0;
}