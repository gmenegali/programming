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
    int w1,w2,h1,h2;

    cin >> w1 >> h1 >> w2 >> h2;

    int result = 0;
    result += 2 * (h1 + h2);
    result += w1 + w2 + 4;
    result += w1 - w2;

    cout << result << endl;    


    return 0;
}