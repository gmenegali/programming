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
 
        ll W, w, H, h, x1, x2, y1, y2;
        cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

        double result = 1e10;
        double partial_result = 1e10;
        if((x2-x1)+w > W and (y2-y1)+h > H){ //Impossible
            partial_result = -1;
            result = min(result, partial_result); 
        }
        if((x2-x1)+w <= W){ //Put on Left
            partial_result = w-x1;
            if(partial_result >= 0)
                result = min(result, partial_result); 
        }
        if((x2-x1)+w <= W){ //Put on Right
            partial_result = w - W + x2;
            if(partial_result >= 0)
                result = min(result, partial_result); 
        }
        if((y2-y1)+h <= H){ //Put down
            partial_result = h-y1;
            if(partial_result >= 0)
                result = min(result, partial_result); 
        }
        if((y2-y1)+h <= H){ //Put up
            partial_result = h - H + y2;
            if(partial_result >= 0)
                result = min(result, partial_result); 
        }
        if((w <= x1) or (h <= y1) or (y2+h <= H) or (x2+w <= W)){ //No need to move
            partial_result = 0;
            if(partial_result >= 0)
                result = min(result, partial_result);
        }
        
        if(result == 1e10)
            cout << -1 << endl;
        else
            printf("%.9f\n", result);
        


        t--;
    }
 
    return 0;
}