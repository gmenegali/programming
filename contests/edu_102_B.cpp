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
 

string factor(string s, int n){
    string result = "";

    for(int i=0; i<n; i++){
        result.PB(s[i]);
        int n_result = (int) result.size();
        bool found = true;
        for(int j=i+1; j<n; j++){
            if(s[j] != result[j%n_result]){
                found = false;
                break;
            }
        }
        if(found){
            if(n % n_result == 0) return result;
            else return s;
        }
    }

    return s;
}

int gcd(int a, int b){
    if(b==0) return a;
    else return gcd(b,a%b);
}

int lcm(int a, int b){
    int GCD = gcd(max(a,b), min(a,b));
    int result = a*b/GCD;
    return result;
}

int main(){
    int t;
 
    cin >> t;
    while(t){
        string s1, s2;
        cin >> s1 >> s2;
        int n1 = (int) s1.size();
        int n2 = (int) s2.size();

        string f1 = factor(s1,n1);
        int n_f1 = (int) f1.size();
        string f2 = factor(s2,n2);
 
        if(f1 == f2){
            int mmc = lcm(n1/n_f1, n2/n_f1);
            for(int i=0; i<mmc; i++){
                cout << f1;
            }
            cout << endl;
        }
        else{
            cout << -1 << endl;
        }

        t--;
    }
 
    return 0;
}