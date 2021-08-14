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

bool bigger(vector<vi> &v, int i, int j){
    if(i == j) return true;
    int count = 0;
    for(int a=0; a<5; a++){
        if(v[i][a] < v[j][a])
            count++;
    }
    if(count >= 3) return true;
    else return false;
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n;
        cin >> n;

        vector<vi> v;

        int a,b,c,d,e;
        for(int i=0; i<n; i++){
            cin >> a >> b >> c >> d >> e;
            vi line = {a,b,c,d,e};
            v.PB(line);
        }

        int result = 0;
        for(int i=0; i<n; i++){
            if(!bigger(v,result,i)){
                result = i;
            }
        }

        bool success = true;
        for(int i=0; i<n; i++){
            if(!bigger(v,result,i)){
                success = false;
            }
        }

        if(!success) cout << -1 << endl;
        else cout << result+1 << endl;
        
        t--;
    }
 
    return 0;
}