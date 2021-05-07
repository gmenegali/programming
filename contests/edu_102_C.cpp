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
 
    cin >> t;
    while(t){
 
        int n, k;
        // vi a;
        cin >> n >> k;
        // vi b(n);
        vi p(k, -1);
 
        // for(int i=1; i<k; i++){
        //     a.PB(i);
        // }
        // for(int i=k; i>=2*k-n; i--){
        //     a.PB(i);
        // }

        int palindromic_size = 2*(n-k)+1;
        int elements_out_of_palindrome = n-palindromic_size;
        
        for(int i=0; i<elements_out_of_palindrome; i++){
            p[i] = i+1;
        }
        int aux = k;
        for(int i=elements_out_of_palindrome; i<k; i++){
            p[i] = aux;
            aux--;
        }

        // for(int i=0; i<n; i++){
        //     b[i] = p[a[i]-1];
        // }
        
        // printVec(a);
        printVec(p);
        // printVec(b);

        t--;
    }
 
    return 0;
}