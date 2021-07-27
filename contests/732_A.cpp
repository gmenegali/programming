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
 
        int n, x, m;
        vi a;
        vi b;
        cin >> n;

        int sum_a = 0, sum_b = 0;
 
        for(int i=0; i<n; i++){
            cin >> x;
            sum_a += x;
            a.PB(x);
        }
        for(int i=0; i<n; i++){
            cin >> x;
            sum_b += x;
            b.PB(x);
        }

        if(sum_a != sum_b)
            cout << -1 << endl;
        else{
            int result = 0;
            for(int i=0; i<n; i++){
                result += abs(a[i]-b[i]);
            }
            cout << result/2 << endl;
            
            for(int i=0; i<n; i++){
                while(a[i] > b[i]){
                    for(int j=0; j<n; j++){
                        while(a[j] < b[j]){
                            cout << i+1 << " " << j+1 << endl;
                            a[i]--;
                            a[j]++;
                            if(a[i] == b[i]) break;
                        }
                        if(a[i] == b[i]) break;
                    }
                }
            }

        }

 
 
        t--;
    }
 
    return 0;
}