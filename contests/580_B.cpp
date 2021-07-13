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
    int n, x;
    vi v;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x;
        v.PB(x);
    }

    ll result = 0, negatives = 0, zeros = 0;

    for(int i=0; i<n; i++){
        if(v[i] < 0){
            negatives++;
            result += abs(v[i] + 1);
        }
        else if(v[i] == 0){
            zeros++;
            result++;
        }
        else{
            result += v[i] - 1;
        }
    }

    if(negatives % 2 != 0 and zeros == 0){
        result += 2;
    }

    cout << result << endl;
 
    return 0;
}