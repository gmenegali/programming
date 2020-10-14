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
        vector<int> testCase;
        vector<int> extremes;
        int n, k;
        string s;
        cin >> n >> k >> s;

        if(s[0] != 'L')
            testCase.push_back(0);

        int wins = 0, win_streaks=0;
        for(int i=0; i<n; i++){
            char c = s[i];
            int count = 0;
            while(s[i] == c and i < n){
                count++;
                i++;
            }
            if(c == 'W'){
                wins += count;
                win_streaks++;
            }
            testCase.push_back(count);
            i--;
        }

        int extremes_sum = 0;
        if(testCase[0] != 0)
            extremes_sum += testCase[0];
        if((int) testCase.size() % 2 != 0)
            extremes_sum += testCase[(int) testCase.size()-1];


        vector<int> l_values;
        for(int i=0; i<(int) testCase.size(); i+=2){
            if(i != 0 and i != (int) testCase.size() -1){
                l_values.push_back(testCase[i]);
            } 
        }
        sort(l_values.begin(), l_values.end());
        
        int k_extreme = 0;
        for(int i=0; i<(int) l_values.size(); i++){
            if(k >= l_values[i]){
                k -= l_values[i];
                wins += l_values[i];
                win_streaks--;
            }
            else if(k > 0 and k < l_values[i]){
                wins += k;
                k = 0;
            }
            else{
                break;
            }
        }

        // cout << "K: " << extremes_sum << endl;
        if(k > 0 and extremes_sum > 0){
            k_extreme = min(k, extremes_sum);
            if(win_streaks == 0)
                win_streaks++;
        }
        // cout << wins << " " << win_streaks << endl;
        // cout << "K: " << " " << k << endl;
        cout << 2*(wins+k_extreme) - win_streaks << endl;

        t--;
    }
 
    return 0;
}