#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define len(s) (int) s.size()
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
 
        int n, x, mini=INT_MAX, maxi=INT_MIN, min_pos=-1, max_pos=-1;
        vi v;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            if(x < mini){
                mini = x;
                min_pos = i;
            }
            if(x > maxi){
                maxi = x;
                max_pos = i;
            }
        }
        v.PB(min(max_pos, min_pos));
        v.PB(max(max_pos, min_pos));
        
        int result = min(n-v[0], v[1]+1);
        result = min(result, v[0]+1 + n-v[1]);
        cout << result << endl;

        t--;
    }
 
    return 0;
}