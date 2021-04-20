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
    vector<vi> m{
        {2,3},
        {2,3},
        {11,13},
        {101,103},
        {1009,1013},
        {10007,10009},
        {100003,100019},
        {1000003,1000033},
        {10000019,10000079},
        {100000007,100000037}
    };
    vi gcd = {1,1,10,100,1000,10000,100000,1000000,10000000,100000000};

    cin >> t;
    while(t){
        int a,b,c,x,y;
        cin >> a >> b >> c;

        if(c > 1){
            x = m[a+1-c][0]*gcd[c];
            y = m[b+1-c][1]*gcd[c]; 
        }
        else{
            x = m[a][0];
            y = m[b][1]; 
        }

        // cout << x << " " << y << " " << gcd[c] << endl;
        cout << x << " " << y << endl;


        t--;
    }
 
    return 0;
}