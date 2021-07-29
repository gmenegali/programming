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
        int digit;
        ll n;
        cin >> n;

        if(n<=6) cout << 15 << endl;
        else if(n<=8) cout << 20 << endl;
        else if(n<=10) cout << 25 << endl;
        else{
            ll result = 0;
            ll div;
            if(n%2 != 0) n++;
            digit = n%10;
            if(digit == 2){
                n -= 12;
                div = n/10;
                result += 30;
                result += 25*div;
            }
            else if(digit == 4){
                n -= 14;
                div = n/10;
                result += 35;
                result += 25*div;
            }
            else if(digit == 6){
                n -= 6;
                div = n/10;
                result += 15;
                result += 25*div;
            }
            else if(digit == 8){
                n -= 8;
                div = n/10;
                result += 20;
                result += 25*div;
            }
            else if(digit == 0){
                div = n/10;
                result += 25*div;
            }

            cout << result << endl;
        }


        t--;
    }
 
    return 0;
}