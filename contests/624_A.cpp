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
 
        int a,b;

        cin >> a >> b;
        int target = b-a;
        if(target == 0){
            cout << 0 << endl;
        }
        else if(target > 0){
            if(target%2 == 0) cout << 2 << endl;
            else cout << 1 << endl;
        }
        else{
            if(target%2 == 0) cout << 1 << endl;
            else cout << 2 << endl;
        }


        t--;
    }
 
    return 0;
}