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
        string s;
        cin >> s;

        int count_A = 0;
        int count_B = 0;
        int result = 0;
        for(int i=0; i<(int)s.size(); i++){
            if(s[i] == 'A'){
                count_A++;
            }
            else if(s[i] == 'B'){
                if(count_A > 0){
                    count_A--;
                }
                else{
                    count_B++;
                }
            }
        }

        result = count_A + (count_B%2);
        cout << result << endl;
        t--;
    }
 
    return 0;
}