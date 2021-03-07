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


vi solve(int n, vi test, int x){
    multiset<int> s;
    for(auto e : test){
        s.insert(e);
    }

    vi res;
    for(int i=0; i<n; i++){
        auto it_max = s.end();
        it_max--;
        int complement = x - *(it_max);
        s.erase(it_max);
        auto it_compl = s.find(complement);
        if(it_compl == s.end()){
            return {};
        }
        else{
            res.PB(x-complement);
            res.PB(complement);
            x = max(x-complement, complement);
            s.erase(it_compl);
        }
    }

    return res;
}
 
int main(){

    int t, n, x;
    cin >> t;

    while(t--){
        cin >> n;
        vi test;
        unordered_multimap<int, int> mm;
        unordered_set<int> index_used;

        for(int i=0; i<2*n; i++){
            cin >> x;
            mm.emplace(x,i);
            test.PB(x);
        }
        sort(test.begin(), test.end());

        bool ok = false;
        vi res;
        for(int i=0; i<2*n-1; i++){
            x = test[2*n-1] + test[i];
            res = solve(n, test, x); 
            if(res.size()){
                ok = true;
                break;
            }
        }

        if(ok){
            cout << "YES" << endl;
            cout << x << endl;
            for(int i=0; i<n; i++){
                cout << res[2*i] << " " << res[2*i+1] << endl;
            }
        }
        else cout << "NO" << endl;
    }

    return 0;
}
