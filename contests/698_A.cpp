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
 
        int n, x;
        vi v;
        vi colors;
        cin >> n;

        colors.PB(0);
        for(int i=0; i<n; i++){
            cin >> x;
            bool found = false;
            for(int j=0; j<(int) colors.size(); j++){
                if(x > colors[j]){
                    colors[j] = x;
                    found = true;
                    break;
                }
            }
            if(found == false) colors.PB(x);

            v.PB(x);
        }
 
        cout << (int) colors.size() << endl;
 
        t--;
    }
 
    return 0;
}