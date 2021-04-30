#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
 
#define PB push_back
using namespace std;
typedef vector<int> vi;

template <class vector_type>
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
 
int main(){
    int n,d,r;

    while(cin >> n >> d >> r){
        if(n ==0 and d==0 and r==0)
            break;
        
        int x, amount=0;
        vi morning;
        vi evening;
 
        for(int i=0; i<n; i++){
            cin >> x;
            morning.PB(x);
        }

        for(int i=0; i<n; i++){
            cin >> x;
            evening.PB(x);
        }

        sort(morning.begin(), morning.end());
        sort(evening.begin(), evening.end());
        
        for(int i=0; i<n; i++){
            if(morning[i] + evening[n-1-i] > d){
                amount += abs(d-(morning[i] + evening[n-1-i]))*r;
            }
        }

        cout << amount << endl;

    }
 
    return 0;
}