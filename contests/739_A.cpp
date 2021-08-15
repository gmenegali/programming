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

    vi numbers;
    int count = 0, index=1;
    while(count != 1001){
        if(index % 3 != 0 and index % 10 != 3){
            count++;
            numbers.PB(index);
        }
        index++;
    }

    cin >> t;
    while(t){
 
        int n;
        cin >> n;
        cout << numbers[n-1] << endl;

        t--;
    }
 
    return 0;
}