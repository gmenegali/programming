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
 
        int n, a, b, l;
        string s;
        cin >> n >> a >> b >> s;

        int result = 0;
        if(b>=0){
            result += (a+b)*n;
        }
        else{
            int ones = 0, zeros = 0;
            char last = s[0];
            if(last == '0') zeros++;
            else ones++;
            for(int i=1; i<n; i++){
                if(s[i] != last){
                    if(last == '0'){
                        zeros++;
                        last = '1';
                    }
                    else{
                        ones++;
                        last = '0';
                    }
                }
            }

            if(ones > zeros){
                int count_ones = 0;
                for(int i=0; i<n; i++){
                    l = 0;
                    while(i<n and s[i] == '0'){
                        l++;
                        i++;
                    }
                    if(l>0) result += a*l+b;
                    if(s[i] == '1') count_ones++;
                }
                result += count_ones*a+b;
            }
            else{
                int count_zeros = 0;
                for(int i=0; i<n; i++){
                    l = 0;
                    while(i<n and s[i] == '1'){
                        l++;
                        i++;
                    }
                    if(l>0) result += a*l+b;
                    if(s[i] == '0') count_zeros++;
                }
                result += count_zeros*a+b;
            }

        }

        cout << result << endl;
        
 
 
        t--;
    }
 
    return 0;
}