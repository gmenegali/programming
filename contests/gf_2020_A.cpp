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
    int t, n, x;
    vector<int> a;
    vector<int> b;
    vector<int> c;
 
    cin >> t;
    while(t){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> x;
            a.push_back(x);
        }
        for(int i=0; i<n; i++){
            cin >> x;
            b.push_back(x);
        }
        for(int i=0; i<n; i++){
            cin >> x;
            c.push_back(x);
        }
 
        int last = -1;
        for(int i=0; i<n; i++){
            if(i != n-1 and last != a[i]){
                cout << a[i] << " ";
                last = a[i];
            }
            else if(i != n-1 and last != b[i]){
                cout << b[i] << " ";
                last = b[i];
            }
            else if(i != n-1 and last != c[i]){
                cout << c[i] << " ";
                last = c[i];
            }
            else{
                if(a[0] != a[i] and last != a[i]){
                    cout << a[i] << " ";
                    last = a[i];
                }
                else if(a[0] != b[i] and last != b[i]){
                    cout << b[i] << " ";
                    last = b[i];
                }
                else if(last != c[i] and last != c[i]){
                    cout << c[i] << " ";
                    last = c[i];
                }
            }
        }
        cout << endl;
 
 
 
        a.clear();
        b.clear();
        c.clear();
        t--;
    }
 
 
    return 0;
}