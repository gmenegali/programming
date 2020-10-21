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
 
        int biggest;
        int biggest_index;
        int first;
        bool diff = false;

        for(int i=0; i<n; i++){
            cin >> x;
            if(i==0){
                first = x;
                biggest = x;
                biggest_index = i;
            }
            if(diff == false and first != x){
                diff = true;
            }

            if(x > biggest){
                biggest = x;
                biggest_index = i;
            }
            testCase.push_back(x);
        }

        if(diff){
            for(int i=0; i<n; i++){
                if(i<n-1){
                    if(testCase[i] == biggest or testCase[i+1] == biggest){
                        if(testCase[i] == biggest and testCase[i+1] != biggest){
                            biggest_index = i;
                        }
                        else if(testCase[i+1] == biggest and testCase[i] != biggest){
                            biggest_index = i+1;
                        }
                    }
                }
            }
            cout << biggest_index+1 << endl;
        }
        else{
            cout << -1 << endl;
        }

        t--;
    }
 
    return 0;
}