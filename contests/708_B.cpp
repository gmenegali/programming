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
 
        int n, x, m;
        unordered_map<int,int> mp;
        cin >> n >> m;
 
        for(int i=0; i<n; i++){
            cin >> x;
            if(mp.find(x%m) != mp.end())
                mp[x%m]++;
            else
                mp[x%m] = 1;
        }

        int count = 0;
        while(!mp.empty()){
            auto item = mp.begin();
            auto complement = mp.find((m-(item->first))%m);
            if(complement != mp.end()){
                if(complement->second > item->second){
                    count++;
                    count += max(0, complement->second - item->second -1);
                }
                else if(complement->second < item->second){
                    count++;
                    count += max(0, item->second - complement->second -1);
                }
                else{
                    count++;
                }

                mp.erase(mp.find(item->first));
                if(mp.find(complement->first) != mp.end()){
                    mp.erase(mp.find(complement->first));
                }
            }
            else{
                count += item->second;
                mp.erase(mp.find(item->first));
            }
        }
        
        cout << count << endl;
        t--;
    }
 
    return 0;
}