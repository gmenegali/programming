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
    if(b == 0) return a;
    return gcd(b, a%b);
}
 
int main(){
    int t;
    vi crive(1000,0);
    vi primes;
    for(int i=2; i<35; i++){
        if(crive[i] == 0){
            primes.PB(i);
            int j = 2*i;
            while(j<1000){
                crive[j] = 1;
                j+=i;
            }
        }
    }

    cin >> t;
    while(t){
 
        int n, x, m=1;
        vi v;
        vi solution;
        cin >> n;

 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }
        
        unordered_map<int,int> h;
        for(int i=0; i<n; i++){
            int index = 0;
            while(v[i] % primes[index] != 0) index++;
            int smallest_prime = primes[index];

            if(h.find(smallest_prime) != h.end()){
                solution.PB(h[smallest_prime]);
            }
            else{
                solution.PB(m);
                h[smallest_prime] = m++;
            }
        }

        cout << --m << endl;
        printVec(solution);
        // printVec(primes);
 
        t--;
    }
 
    return 0;
}