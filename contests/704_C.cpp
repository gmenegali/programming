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
    int m,n;
    string s, t;
    cin >> m >> n;
    cin >> s >> t;

    unordered_map<char,vi> hash;
    for(int i=0; i<m; i++){
        if(hash.find(s[i]) != hash.end())
            hash[s[i]].PB(i);
        else
            hash[s[i]] = {i};
    }

    //MIN
    vector<vi>mm; //min_max of each char of t
    int current_index = -1;
    for(int i=0; i<n; i++){
        auto it = upper_bound(hash[t[i]].begin(), hash[t[i]].end(), current_index);
        current_index = *it;
        // cout << current_index+1 << endl;
        mm.PB({current_index});
    }

    //MAX
    current_index = m;
    int target=-999;
    for(int i=n-1; i>=0; i--){
        //Binary Search
        int k = 0;
        for(int b = (int) hash[t[i]].size()/2; b > 0; b/=2){
            while(b+k < (int) hash[t[i]].size() and hash[t[i]][b+k] < current_index) k += b; 
        }
        target=hash[t[i]][k];
        mm[i].PB(target);
        current_index = target;
        // cout << current_index << endl;
    }

    int result = 0;
    for(int i=0; i<(int)mm.size()-1; i++){
        result = max(result, abs(mm[i][0] - mm[i+1][0]));
        result = max(result, abs(mm[i][0] - mm[i+1][1]));
        result = max(result, abs(mm[i][1] - mm[i+1][0]));
        result = max(result, abs(mm[i][1] - mm[i+1][1]));
    }    
    cout << result << endl;

    // for(int i=0; i<n; i++){
    //     cout << t[i] << " ";
    //     printVec(hash[t[i]]);
    // }
    // cout << endl;
    // for(int i=0; i<(int)mm.size(); i++){
    //     cout << t[i] << " ";
    //     printVec(mm[i]);
    // }    



    return 0;
}