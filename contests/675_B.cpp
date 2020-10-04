#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
void printVec(vector<int> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

ll calc_min(ll a, ll b, ll c, ll d){
    ll result = INT_MAX;
    result = min(result, (abs(a-b)+abs(a-c)+abs(a-d)));
    result = min(result, (abs(b-a)+abs(b-c)+abs(b-d)));
    result = min(result, (abs(c-a)+abs(c-b)+abs(c-d)));
    result = min(result, (abs(d-a)+abs(d-c)+abs(d-b)));

    // cout << "RESULT: " << result << endl;
    return result;
}
 
int main(){
    int t, n, m, x;
    vector<int> testCase;
    vector<vector<int>> matrix;

    cin >> t;
    while(t){
        cin >> n >> m;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> x;
                testCase.push_back(x);
            }
            matrix.push_back(testCase);
            testCase.clear();
        }

        ll result = 0;
        for(int i=0; i<n/2 + (n%2 != 0); i++){
            for(int j=0; j<m/2 + (m%2 != 0); j++){
                if(i != n/2){
                    if(j != m/2){
                        result += calc_min((ll) matrix[i][j], (ll) matrix[i][m-1-j], (ll) matrix[n-1-i][j], (ll) matrix[n-1-i][m-1-j]);
                    }
                    else{
                        result += calc_min((ll) matrix[i][j], (ll) matrix[i][m-1-j], (ll) matrix[n-1-i][j], (ll) matrix[n-1-i][m-1-j])/2;
                    }
                }
                else {
                    if(j != m/2){
                        result += calc_min((ll) matrix[i][j], (ll) matrix[i][m-1-j], (ll) matrix[n-1-i][j], (ll) matrix[n-1-i][m-1-j])/2;
                    }
                    else{
                        result += calc_min((ll) matrix[i][j], (ll) matrix[i][m-1-j], (ll) matrix[n-1-i][j], (ll) matrix[n-1-i][m-1-j])/4;
                    }                    
                }
                // matrix[i][j]; //1
                // matrix[i][m-1-j] //4
                // matrix[n-1-i][j] //9
                // matrix[n-1-i][m-1-j] //18
            }
        }

        // for(auto line : matrix){
        //     printVec(line);
        // }
        // cout << endl;

        cout << result << endl;
        
        
        matrix.clear();
        t--;
    }
 
    return 0;
}