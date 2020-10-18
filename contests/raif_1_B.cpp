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
        int n;
        string s;
        cin >> n >> s;

        //Is complete in clockwise?
        bool complete = true;
        int off = 0;
        set<int> off_nodes;
        for(int i=0; i<n; i++){
            if(s[i] == '-'){
                off_nodes.insert(i%n);
                off_nodes.insert((i+1)%n);
                off++;
            }

            if(s[i] == '<'){
                complete = false;
            }
        }
        if(complete == false){
            complete = true;
            //Is complete in anticlockwise?
            for(int i=0; i<n; i++){
                if(s[i] == '>'){
                   complete = false;
                    break;
                }
            }
        }

        if(complete){
            cout << n << endl;
        }
        else{
            off = (int) off_nodes.size();
            cout << off << endl;
        }

 
        t--;
    }
 
    return 0;
}