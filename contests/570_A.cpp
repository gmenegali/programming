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

int sum_digits(int a){
    int sum = 0;
    while(a > 0){
        sum += a%10;
        a /= 10;
    }
    return sum;
}
 
int main(){
    int a, sum;
 
    cin >> a;

    sum = sum_digits(a);
    while(sum % 4 != 0){
        a++;
        sum = sum_digits(a);
    }

    cout << a << endl;

    return 0;
}