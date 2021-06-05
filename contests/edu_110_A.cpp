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
        vi v;
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        v.PB(a);
        v.PB(b);
        v.PB(c);
        v.PB(d);

        sort(v.begin(), v.end());
        if(v[0] == a or v[0] == b){
            if(v[1] == c or v[1] == d){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            if(v[1] == a or v[1] == b){
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
 
        t--;
    }
 
    return 0;
}