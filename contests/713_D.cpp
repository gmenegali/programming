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

void print_ans(vi v, int x, int y){
    for(int i=0; i<(int)v.size(); i++){
        if(i != x and i != y){
            cout << v[i] << " ";
        }
    }
    cout << endl;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, x;
        vi v;
        cin >> n;
 
        ll sum = 0, current_sum = 0;
        for(int i=0; i<n+2; i++){
            cin >> x;
            sum += x;
            v.PB(x);
        }

        sort(v.begin(), v.end());

        bool ans = false;
        ll target_sum1 = v[(int) v.size()-1];
        current_sum = sum - target_sum1;
        for(int i=0; i<n+1; i++){
            if(current_sum - v[i] == target_sum1){
                print_ans(v, i, n+1);
                ans = true;
                break;
            }
        }

        if(!ans){
            ll target_sum2 = v[(int) v.size()-2];
            current_sum = sum - target_sum2;
            for(int i=0; i<n+2; i++){
                if(i != n and current_sum - v[i] == target_sum2){
                    print_ans(v, i, n);
                    ans = true;
                    break;
                }
            }
        }

        if(!ans){
            cout << -1 << endl;
        }
 
        t--;
    }
 
    return 0;
}