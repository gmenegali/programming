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

int calc(int a, int b, int c){
    return (abs(a-b) + abs(a-c) + abs(b-c));
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        vi v;
        for(int i=0; i<3; i++){
            int x;
            cin >> x;
            v.PB(x);
        }
        sort(v.begin(), v.end());
        int a =v[0], b=v[1], c=v[2];

        if(a != b and b != c and a != c){
            cout << calc(a+1,b,c-1) << endl;
        }
        else if((a == b and b != c) or (a != b and b == c) or (a == c and b != c)){
            if(a == b){
                if(c-1 != b){
                    cout << calc(a+1,b+1,c-1) << endl;
                }
                else{
                    cout << calc(a,b,c-1) << endl;
                }
            }
            else{
                if(a+1 != b){
                    cout << calc(a+1,b-1,c-1) << endl;
                }
                else{
                    cout << calc(a+1,b,c) << endl;
                }
            }
        }
        else{
            cout << 0 << endl;
        }


        t--;
    }
 
    return 0;
}