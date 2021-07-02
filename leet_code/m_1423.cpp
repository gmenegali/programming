#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

template <class vector_type>
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

class Solution {
public:
    int max(int a, int b){
        return a<=b ? b : a;
    }

    int maxScore(vector<int>& cardPoints, int k) {
        int n = (int) cardPoints.size();
        int result = 0, sum_front = 0, sum_back = 0;
        for(int i=0; i<k; i++) sum_front += cardPoints[i];
        
        result = sum_front;
        for(int i=0; i<k; i++){
            sum_front += cardPoints[n-1-i] - cardPoints[k-1-i];
            result = max(result, sum_front);
        }

        return result;
    }
};
 
int main(){

    Solution s;
    vector<int> cardPoints = {1,2,3,4,5,6,1};
    int k = 3;
    cout << s.maxScore(cardPoints, k) << endl;
    cardPoints = {2,2,2};
    k = 2;
    cout << s.maxScore(cardPoints, k) << endl;
    cardPoints = {9,7,7,9,7,7,9};
    k = 7;
    cout << s.maxScore(cardPoints, k) << endl;
    cardPoints = {1,1000,1};
    k = 1;
    cout << s.maxScore(cardPoints, k) << endl;
    cardPoints = {1,79,80,1,1,1,200,1};
    k = 3;
    cout << s.maxScore(cardPoints, k) << endl;
 
    return 0;
}