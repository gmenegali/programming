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
 
        int n, x;
        cin >> n;
        vi v;
        vi hash(n, 0);

        int maxi = 0;
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
            maxi = max(maxi, x);
        }

        int mini = n-maxi;
        int count_results = 0;

        //opt1
        bool first_maxi = true;
        for(int i=1; i<=maxi; i++) hash[i] = 0;
        for(int i=0; i<maxi; i++) hash[v[i]]++;
        for(int i=1; i<=maxi; i++){
            if(hash[i] != 1){
                first_maxi = false;
                break;
            }
        }

        bool second_mini = true;
        for(int i=1; i<=mini; i++) hash[i] = 0;
        for(int i=maxi; i<n; i++) hash[v[i]]++;
        for(int i=1; i<=mini; i++){
            if(hash[i] != 1){
                second_mini = false;
                break;
            }
        }

        //opt2
        bool first_mini = true;
        for(int i=1; i<=mini; i++) hash[i] = 0;
        for(int i=0; i<mini; i++) hash[v[i]]++;
        for(int i=1; i<=mini; i++){
            if(hash[i] != 1){
                first_mini = false;
                break;
            }
        }

        bool second_maxi = true;
        for(int i=1; i<=maxi; i++) hash[i] = 0;
        for(int i=mini; i<n; i++) hash[v[i]]++;
        for(int i=1; i<=maxi; i++){
            if(hash[i] != 1){
                second_maxi = false;
                break;
            }
        }

        if(first_maxi and second_mini) count_results++;
        if(first_mini and second_maxi and mini != maxi) count_results++;
        cout << count_results << endl;
        if(first_maxi and second_mini) cout << maxi << " " << mini << endl; 
        if(first_mini and second_maxi and mini != maxi) cout << mini << " " << maxi << endl;

        t--;
    }
 
    return 0;
}