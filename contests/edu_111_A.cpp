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
 
        int n, x;
        vi v;
        cin >> n;

        int current = 1;
        int sum = 0;

        while(sum != n){
            if(n-sum >= current){
                sum += current;
                v.PB(current);
                current += 2;
            }
            else{
                v.PB(n-sum);
                sum = n;
            }
        }

 
        cout << v.size() << endl;
 
        t--;
    }
 
    return 0;
}