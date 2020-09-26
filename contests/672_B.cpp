#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

bool my_sort(pair<int,int> a, pair<int,int> b){
    return a.first < b.first;
}

int my_log2(int n){
    int result = 0;
    while(n >= 2){
        result++;
        n = n/2;
    }

    return result;
}

ll choose_2(int n){
    ll result = (ll) n * (ll) (n-1);
    return result/2;
}

int main(){
    int t, n, x;
    unordered_map<int,int> m;

    cin >> t;
    while(t){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            int val = my_log2(x);
            if(m.find(val) == m.end()){
                m[val] = 1;
            }
            else{
                m[val]++;
            }
        }

        ll result = 0;
        for(auto i: m){
            // cout << i.first << " " << i.second << endl;
            if(i.second > 1)
                result += choose_2(i.second);
        }
        
        cout << result << endl;

        m.clear();
        t--;
    }


    return 0;
}