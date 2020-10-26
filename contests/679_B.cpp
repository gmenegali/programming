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

        unordered_map<int,vi> mp;
 
        int key;
        for(int i=0; i<n; i++){
            testCase.clear();
            for(int j=0; j<m; j++){
                cin >> x;
                testCase.push_back(x);
                if(j==0) 
                    key=x;
            }
            mp[key] = testCase;
        }

        // for(auto it=mp.begin(); it!=mp.end(); it++){
        //     printVec(it->second);
        // }

 
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                cin >> x;
                if(mp.find(x) != mp.end()){
                    printVec(mp[x]);
                }
            }
        }
 
        t--;
    }
 
    return 0;
}