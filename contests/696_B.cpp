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

    vector<int> table(21000, -1);
    table[0] = 0;
    table[1] = 0;
    vector<int> primes;
    for(int i=0; i<(int)table.size(); i++){
        if(table[i] == -1){
            primes.PB(i);
            for(int j=i; j<(int)table.size(); j+=i){
                table[j] = 0;
            }

        }
    }
    // printVec(primes);

 
    cin >> t;
    while(t){
        vector<int> testCase;
        int d;
        cin >> d;
        ll prime1=-1, prime2=-1, d2=d;
        for(int i=0; i<(int)primes.size(); i++){
            while(d2+1 > primes[i]){
                i++;
            }
            prime1 = primes[i];
            
            while(primes[i]-prime1 < d2){
                i++;
            }
            prime2 = primes[i];
            break;
        }
        ll ans = prime1*prime2; 
        cout << ans << endl;
 
        t--;
    }
 
    return 0;
}