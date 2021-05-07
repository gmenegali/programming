#include <iostream>
#include <cstdio>
#include <vector>

#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <= b; i++)
#define len(a) (int) a.size()
using namespace std;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pi;
template <class vector_type>
 
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

vs digits = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};

void backtracking(vs &ans, vs &words, bool digit){
    if(digit){
        if(len(ans) == 0){
            for(auto digit : digits){
                ans.PB(digit);
            }
        }
        else{
            vs copy = ans;
            ans.clear();
            for(int i=0; i<len(copy); i++){
                for(auto digit : digits){
                    string aux = copy[i];
                    ans.PB(aux.append(digit));
                }
            }
        }
    }
    else{
        if(len(ans) == 0){
            for(auto word : words){
                ans.PB(word);
            }
        }
        else{
            vs copy = ans;
            ans.clear();
            for(int i=0; i<len(copy); i++){
                for(auto word : words){
                    string aux = copy[i];
                    ans.PB(aux.append(word));
                }
            }
        }
    }
}

void solve(string rule, vs &words){
    vs ans;
    for(int i=0; i<len(rule); i++){
        if(rule[i] == '#'){
            backtracking(ans, words, false);
        }
        else{
            backtracking(ans, words, true);
        }
    }

    for(auto password : ans){
        cout << password << endl;
    }
}
 
int main(){

    int n, m;
    
    while(cin >> n){
        vs words;
        vs rules;
        string s;

        for(int i=0; i<n; i++){
            cin >> s;
            words.PB(s);
        }

        cin >> m;

        for(int i=0; i<m; i++){
            cin >> s;
            rules.PB(s);
        }

        cout << "--" << endl;
        for(auto rule : rules){
            solve(rule, words);
        }
    }
 
 
    return 0;
}