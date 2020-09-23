#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>

#define ll long long int

using namespace std;

void printVec(vector<int> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

int main(){
    int t, n;
    string positive;

    cin >> t;
    while(t){
        cin >> n >> positive;
        int winner = -1;
        if(n %2 == 0){ // Brench
            for(int i=1; i<n; i+=2){
                if(((int) positive[i] - 48) % 2 == 0)
                    winner = 2;
            }
            if(winner == -1)
                winner = 1;
        } else{ // Raze
            for(int i=0; i<n; i+=2){
                if(((int) positive[i] - 48) % 2 != 0)
                    winner = 1;
            }
            if(winner == -1)
                winner = 2;
        }

        cout << winner << endl;

        t--;
    }


    return 0;
}