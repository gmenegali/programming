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

int binary_search(vi &v, int target, int l, int h){
    int a = 2;
    if(l>h) return -1;
    int middle = (l+h)/2;
    if(target == v[middle]) return middle;

    if(target < v[middle]){
        return binary_search(v, target, l, middle-1);
    }
    else{
        return binary_search(v, target, middle+1, h);
    }
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, k, x;
        vi v;
        cin >> n >> k;
 
        for(int i=0; i<n; i++){
            cin >> x;
            v.PB(x);
        }

        vi copy = v;
        sort(copy.begin(), copy.end());

        int count = 0;
        for(int i=0; i<n; i++){
            int index = binary_search(copy, v[i], 0, (int)copy.size());
            count++;
            while(i<n and index < n and v[i] == copy[index]){
                index++;
                i++;
            }
            i--;
        }

        if(k >= count)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
 
        t--;
    }
 
    return 0;
}