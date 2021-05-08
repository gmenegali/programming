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
    return gcd(b, a%b);
}

int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, x;
        vi v;
        cin >> n;

        int minimum = 2e9;
        int min_index = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x < minimum){
                minimum = min(minimum, x);
                min_index = i;
            }
            v.PB(x);
        }
        // printVec(v);

        if(min_index != 0){
            cout << n << endl;
        }
        else{
            cout << n-1 << endl;
        }

        int a = minimum;
        for(int i=0; i<n; i++){
            if(i != min_index){
                v[i] = minimum+i;
                cout << i+1 << " " << min_index+1 << " " << minimum+i << " " << minimum << endl;
            }
            a++;
        }        
        
        if(min_index != 0){
            v[min_index] = minimum+min_index;
            cout << min_index+1 << " " << 1 << " " << minimum + min_index << " " << v[0] << endl;
        }
        // printVec(v);
        // cout << endl << endl;
 
        t--;
    }
    

    return 0;
}