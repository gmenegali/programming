#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define len(s) (int) s.size()
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
 
        int n;
        string s;
        cin >> n >> s;

        unordered_map<char,set<char>> h;
        unordered_map<string,set<char>> h_size3;

        for(int i=1; i<n; i++){
            h[s[i-1]].insert(s[i]);
            if(i>1){
                string tmp = "";
                tmp += s[i-2];
                tmp += s[i-1];
                h_size3[tmp].insert(s[i]);
            }
        }
        if(h.find(s[n-1]) == h.end()){
            set<char> aux;
            h[s[n-1]] = aux;
        }
        if((int) h.size() < 26){ //MEX size = 1
            for(char c='a'; c!='z'+1; c++){
                if(h.find(c) == h.end()){
                    cout << c << endl;
                    break;
                }
            }
        }
        else{
            bool size2 = false;
            for(char c='a'; c!='z'+1; c++){
                if((int) h[c].size() < 26){
                    for(char c2='a'; c2!='z'+1; c2++){
                        if(h[c].find(c2) == h[c].end()){ //MEX size = 2
                            cout << c << c2 << endl;
                            size2 = true;
                            break;
                        }
                    }
                    break;
                }
            }

            if(size2 == false){ //MEX size = 3
                vector<string> v;
                for(auto item:h_size3) v.PB(item.first);
                sort(v.begin(), v.end());
                for(int i=0; i<len(v); i++){
                    if((int) h_size3[v[i]].size() < 26){
                        for(char c='a'; c!='z'+1; c++){
                            if(h_size3[v[i]].find(c) == h_size3[v[i]].end()){ //MEX size = 3
                                cout << v[i] << c << endl;
                                break;
                            }
                        }
                        break;
                    }
                }
            }
        }

        t--;
    }
 
    return 0;
}