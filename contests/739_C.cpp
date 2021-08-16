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
 
        int k;
        cin >> k;
        int square = sqrt(k);
        if(square*square < k) square++;
        
        int r, c;
        if(k > square*square - square){
            r = square;
            c = (square*square - k)+1;
        }
        else{
            r = square - (square*square - square - k + 1);
            c = square;
        }


        cout << r << " " << c << endl;


        t--;
    }
 
    return 0;
}