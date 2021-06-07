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

int gcd(int a, int b){
    if(b==0) return a;
    return gcd(b, a%b);
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, x;
        vi v;
        cin >> n;
 
        bool negative = false;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x < 0) negative = true;
            v.PB(x);
        }

        sort(v.begin(), v.end());

        int maxi = v[n-1];
        
        int ratio = v[n-1];
        for(int i=1; i<n; i++){
            ratio = gcd(ratio, v[i]-v[i-1]);
        }
        int mini;
        if(ratio >= v[0]){
            mini = v[0];
        }
        else{
            ratio = gcd(ratio, v[0]-ratio);
            mini = ratio;
        }

        int total = 1 + ((maxi-mini) / ratio);


        if(total <= 300 and negative == false){
            cout << "YES" << endl;
            cout << total << endl;
            for(int i=mini; i<=maxi; i+=ratio){
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
 
        t--;
    }
 
    return 0;
}