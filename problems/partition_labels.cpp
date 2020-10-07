#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;

class Solution {
public:

    void printVec(vector<int> &v){
        for(int i=0; i < (int) v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << endl;
    }

    vector<int> partitionLabels(string S) {
        unordered_map<char,int> first_appearance;
        unordered_map<char,int> last_appearance;
        vector<int> ans;

        for(int i=0; i<(int)S.size(); i++){
            if(first_appearance.find(S[i]) == first_appearance.end()){
                first_appearance[S[i]] = i;
            }
            last_appearance[S[i]] = i;
        }

        int target = last_appearance[S[0]], current_size = 1; 
        for(int i=0; i< (int) S.size(); i++){
            // cout << S[i] << " " << last_appearance[S[i]] << endl;
            if(i == target){
                ans.push_back(current_size);
                if(i != (int) S.size()-1){
                    target = last_appearance[S[i+1]];
                }
                current_size = 1;
            }
            else{
                target = max(last_appearance[S[i]], target);
                current_size++;
            }
        }

        return ans;
    }
};

void printVec(vector<int> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(){
    string s;
    cin >> s;

    Solution sol;
    vector<int> ans = sol.partitionLabels(s); 
    
    return 0;
}