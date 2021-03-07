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
        vi greatest;
        unordered_map<int,int> m;
        vector<int> testCase;
        int n, x;
        cin >> n;

        for(int i=0; i<n; i++){
            cin >> x;
            if((int) greatest.size() == 0){
                greatest.PB(x);
            }
            else{
                if(x>(*(greatest.end()-1))){
                    greatest.PB(x);
                }
                else{
                    greatest.PB(*(greatest.end()-1));
                }
            }
            m[x] = i;
            testCase.push_back(x);
        }
        
        int last_i = n;
        int current_i = n-1;
        while(current_i >= 0){
            current_i = m[greatest[current_i]];
            for(int i=current_i; i<=last_i-1; i++){
                cout << testCase[i] << " ";
            }
            last_i = current_i;
            current_i--;
        }
        cout << endl;
        t--;
    }

    return 0;
}