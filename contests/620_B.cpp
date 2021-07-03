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

bool is_pal(string s){
    int n = (int) s.size();
    for(int i=0; i<n/2; i++){
        if(s[i] != s[n-1-i]) return false;
    }
    return true;
}

string reverse(string s){
    string result = "";
    int n = (int) s.size();
    for(int i=n-1; i>=0; i--){
        result += s[i];
    }
    return result;
}

int main(){
 
    int n, m;
    cin >> n >> m;

    string s;
    string beg="", mid="", end="";
    unordered_set<string> us;

    bool found_pal = false;
    for(int i=0; i<n; i++){
        cin >> s;
        if(us.find(s) != us.end()){
            beg += s;
            end = reverse(s) + end;
            us.erase(s);
        }
        else{
            us.insert(reverse(s));
        }
    }

    for(auto item : us){
        if(is_pal(item)){
            mid = item;
            break;
        }
    }

    cout << beg.size() + mid.size() + end.size() << endl;
    cout << beg << mid << end << endl;
    
    return 0;
}