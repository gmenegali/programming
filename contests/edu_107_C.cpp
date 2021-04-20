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
    int n, q, x;
    cin >> n >> q;

    deque<int> d;
    
    for(int i=0; i<n; i++){
        cin >> x;
        d.push_back(x);
    }

    for(int i=0; i<q; i++){
        cin >> x;
        int j=1;
        for(auto it=d.begin(); it != d.end(); it++){
            if(*it == x){
                d.erase(it);
                d.push_front(x);
                cout << j << " ";
                break;
            }
            j++;
        }
    }
    cout << endl;
 
    return 0;
}