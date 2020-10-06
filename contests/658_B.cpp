#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;

 
int main(){
    int t, n, x;
    
    vector<int> testCase;

    cin >> t;
    while(t){
        cin >> n;
        int result = -1;
        int temporary_result = 1;
        for(int i=0; i<n; i++){
            cin >> x;
            // testCase.push_back(x);
            if(result == -1){
                if(x > 1){
                    result = i % 2;
                }
                if(x == 1){
                    temporary_result++;
                    temporary_result = temporary_result % 2;
                }
            }
        }

        if(result == -1){
            if(temporary_result == 0){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        } 
        else{
            if(result == 0){
                cout << "First" << endl;
            }
            else{
                cout << "Second" << endl;
            }
        }
        
        testCase.clear();
        t--;
    }
 
    return 0;
}