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

bool possible(pi current, pi target, int current_time, int target_time){
    return(abs(current.F - target.F) + abs(current.S - target.S) <= target_time - current_time);
}
 
int main(){
    vector<vi> testCase;
    int n, r, x, y, t;
    
    cin >> r >> n;
    vector<int> ans(n, INT_MIN);

    REP(i, 1, n){
        cin >> t >> x >> y;
        testCase.PB({t,x,y});
    }

    pi current = MP(1,1);
    int current_time = 0;
    REP(i, 1, n){
        int maximum = INT_MIN;
        int choosen_j = -1;
        REP(j, 0, i-1){
            int target_time = testCase[j][0];
            pi target = MP(testCase[j][1], testCase[j][2]);
            if(possible(current, target, current_time, target_time)){
                if(maximum <= ans[j]){
                    maximum = ans[j];
                    choosen_j = j;
                }
            }
        }
        if(choosen_j != -1){
            ans[i-1] = 1 + max(0, ans[choosen_j]);
            current = MP(testCase[choosen_j][1], testCase[choosen_j][2]);
            current_time = testCase[choosen_j][0];
        }
    }

    printVec(ans);
    
 
    return 0;
}