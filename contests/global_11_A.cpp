#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
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
        int n, x;
        vector<int> positives;
        vector<int> znegatives;
        vector<int> ans;
        cin >> n;

        int sum = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            sum += x;
            if(x >0){
                positives.push_back(x);
            }
            else{
                znegatives.push_back(x);
            }
        }
        
        sort(znegatives.begin(), znegatives.end());

        if(sum != 0){
            cout << "YES" << endl;
            if(sum > 0){
                for(int i=0; i<(int)positives.size(); i++){
                    ans.push_back(positives[i]);
                }
                for(int i=0; i<(int)znegatives.size(); i++){
                    ans.push_back(znegatives[i]);
                }
            }
            else{
                for(int i=0; i<(int)znegatives.size(); i++){
                    ans.push_back(znegatives[i]);
                }
                for(int i=0; i<(int)positives.size(); i++){
                    ans.push_back(positives[i]);
                }
            }
            printVec(ans); 
        } else {
            cout << "NO" << endl;
        }
        t--;
    }
 
    return 0;
}