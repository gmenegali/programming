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

        int first=-1, first_pos=-1;
        int second=-1, second_pos=-1;
        for(int i=0; i<n; i++){
            cin >> x;
            if(first == -1){
                first = x;
                first_pos = i;
            }
            else if(second == -1 and x != first){
                second = x;
                second_pos = i;
            }
            testCase.push_back(x);
        }   

        if(second != -1){
            cout << "YES" << endl;
            cout << first_pos + 1 << " " << second_pos + 1 << endl;
            for(int i=0; i<n; i++){
                if(i != first_pos and i!= second_pos){
                    if(testCase[i] != first){
                        cout << i+1 << " " << first_pos+1 << endl;
                    }
                    else{
                        cout << i+1 << " " << second_pos+1 << endl;
                    }
                }
            }   
        }
        else{
            cout << "NO" << endl;
        }

        t--;
    }
 
    return 0;
}