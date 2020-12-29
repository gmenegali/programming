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
        vector<string> v;
        string tmp;
        vector<vector<pair<int,int>>> dp;

        for(int i=0; i<n; i++){
            cin >> tmp;
            vector<pair<int,int>> line;
            pair<int,int> pr;

            int first=-1;
            for(int j=0; j<m; j++){
                if(tmp[j] == '*'){
                    if(first == -1){
                        first = j;
                    }
                    if(j == m-1){
                        pr = make_pair(first, j);
                        line.PB(pr);
                    }
                }
                else{
                    if(first != -1){
                        pr = make_pair(first, j-1);
                        line.PB(pr);
                        first = -1;
                    }
                }
            }
            dp.PB(line);
            v.PB(tmp);
        }

        // for(auto vec : dp){
        //     for(auto p : vec){
        //         cout << "(" << p.first << ", " << p.second << ") ";
        //     }
        //     cout << endl;
        // }

        // cout << endl << endl << endl;

        ll result = 0;
        int k = 1;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == '*'){
                    result++;

                    k=2;
                    while(true){
                        if(i+k-1 >= n) break; // Nothing below
                        else if(j-k+1 < 0 and j+k-1 >= m) break; // Out of next interval
                        else{
                            bool brk = true;
                            int begin = j-k+1;
                            int end = j+k-1;
                            for (auto p : dp[i+k-1]){
                                if(begin >= p.first and begin <= p.second){
                                    if(end <= p.second){
                                        brk = false;
                                        break;
                                    }
                                }
                            }
                            if(brk){
                                break;
                            }
                            else{
                                k++;
                                result++;
                            }
                        }
                    }
                }
            }            
        }


        cout << result << endl;
        t--;
    }
 
    return 0;
}