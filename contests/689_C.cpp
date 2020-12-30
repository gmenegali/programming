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
        vector<int> testCase;
        int n, m, x;
        cin >> n >> m;

        for(int i=0; i<n; i++){
            cin >> x;
            testCase.push_back(x);
        }

        int index = n-1;
        for(; index>=0; index--){
            if(testCase[index] != index+1){
                break;
            }
        }
        index++;

        int r;
        double p, p_result=1;
        for(int i=0; i<m; i++){
            cin >> r >> p;
            if(r >= index){
                p_result *= (1-p);
            }
        }

        if(index == 0){
            cout << 1 << endl;
        }
        else{
            cout << 1-p_result << endl;
        }
 
        t--;
    }
 
    return 0;
}