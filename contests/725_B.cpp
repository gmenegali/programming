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

        ll sum = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            sum += x;
            v.PB(x);
        }

        if(sum % n == 0){
            int avg = sum / n;
            int result = 0;
            for(int i=0; i<n; i++){
                if(v[i] > avg) result++;
            }
            cout << result << endl;
        }
        else{
            cout << -1 << endl;
        }

        


 
 
        t--;
    }
 
    return 0;
}