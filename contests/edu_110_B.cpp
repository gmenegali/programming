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

int gcd(int a, int b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}
 
int main(){
    int t;
    cin >> t;
    while(t){
 
        int n, x;
        vi v;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        sort(v.rbegin(), v.rend());

        int total = 0;
        int aux = n-1;

        for(int i=0; i<n; i++){
            if(v[i] % 2 == 0){
                total += aux;
                aux--;
            }
            else{
                for(int j=i+1; j<n; j++){
                    if(v[j] % 2 != 0 and gcd(v[i],v[j]) > 1) total++;
                }
            }
        }

        cout << total << endl;
 
        t--;
    }
    
    return 0;
}