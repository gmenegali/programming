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
        int n, x;
        cin >> n;

        int first_one = -1, last_one = -1;
        for(int i=0; i<n; i++){
            cin >> x;
            if(x == 1 and first_one == -1){
                first_one = i;
            }
            else if(x == 1){
                last_one = i;
            }
            testCase.push_back(x);
        }

        if(last_one != -1){
            int result = 0;
            for(int i=first_one; i<=last_one; i++){
                if(testCase[i] == 0){
                    result++;
                }
            }
            cout << result << endl;
        }
        else{
            cout << 0 << endl;
        }
 
        t--;
    }
 
    return 0;
}