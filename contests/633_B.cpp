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
 
        int n, x;
        vi v;
        deque<int> d;
        cin >> n;
 
        for(int i=0; i<n; i++){
            cin >> x;
            d.PB(x);
            v.PB(x);
        }
        sort(d.begin(), d.end());

        stack<int> s;
        int turn = 0;
        while(!d.empty()){
            if(turn == 0){
                s.push(d.front());
                d.pop_front();
            }
            else{
                s.push(d.back());
                d.pop_back();

            }
            turn += 1;
            turn %= 2;
        }

        while(!s.empty()){
            int ans = s.top();
            cout << ans << " ";
            s.pop();
        }
        cout << endl;
        t--;
    }
 
    return 0;
}