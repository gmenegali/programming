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
 
        int n, result;
        vi v;
        cin >> n;

        int m = n;
        vi digits;
        while(m>=10){
            digits.PB(m%10);
            m/=10;
        }
        digits.PB(m);
        // printVec(digits);
        int d = (int) digits.size();

        
        result = 9*(d-1);
        int extra = digits[d-1]-1;
        int include = 0;
        int cmp = digits[d-1];
        for(int i=0; i<d-1; i++){
            cmp *=10;
            cmp += digits[d-1];
        }
        if(n >= cmp) include = 1;
        result += extra + include;

        cout << result << endl;
 
 
        t--;
    }
 
    return 0;
}