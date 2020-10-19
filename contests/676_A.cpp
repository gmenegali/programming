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
        vector<int> testCase;
        int a, b;
        cin >> a >> b;

        bitset<30> a2, b2, ans;

        a2 = a;
        b2 = b;
        for(int i=0; i<30; i++){
            if(a2[i] == 1 and b2[i] == 1){
                ans[i] = 1;
            }
            else{
                ans[i] == 0;
            }
        }
        a2 = a2 ^ ans;
        b2 = b2 ^ ans;
        a2 = a2 ^ b2;
        
        int real_ans = (int) a2.to_ulong();
        cout << real_ans << endl;
        t--;
    }
 
    return 0;
}