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

    ll n, x;
    cin >> n;
    ll negative_counter = 0, even_negatives = 0, odd_negatives = 0;
    ll total = (n+1)*n/2;
    ll pos=0, neg=0;

    for(int i=0; i<n; i++){
        cin >> x;
        if(negative_counter % 2 == 0) even_negatives++;
        else odd_negatives++;

        if(x < 0) negative_counter++;
        if(negative_counter % 2 == 0){
            pos += even_negatives;
        }
        else pos += odd_negatives;
    }
    cout << total - pos << " " << pos << endl;
 
    return 0;
}