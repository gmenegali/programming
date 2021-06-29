#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (ll i = a; i <= b; i++)
#define len(s) (ll) s.size()
using namespace std;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
template <class vector_type>
 
void prllVec(vector<vector_type> &v){
    for(ll i=0; i < (ll) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}

class pos{
public:
    ll x, y;
    pos(ll x1, ll y1){
        x = x1;
        y = y1;
    }
};

ll dist(pos a, pos b){
    return (abs(a.x-b.x) + abs(a.y-b.y));
}


pos max_dist(pos a1, pos a2, pos a3, pos a4, pos target){
    ll x=-1, y=-1, current = INT_MIN;
    
    if(dist(target, a1) > current){
        current = dist(target, a1);
        x = a1.x;
        y = a1.y;
    }

    if(dist(target, a2) > current){
        current = dist(target, a2);
        x = a2.x;
        y = a2.y;
    }

    if(dist(target, a3) > current){
        current = dist(target, a3);
        x = a3.x;
        y = a3.y;
    }

    if(dist(target, a4) > current){
        current = dist(target, a4);
        x = a4.x;
        y = a4.y;        
    }

    pos result(x,y);
    return result;
}


int main(){
    ll t;
 
    cin >> t;
    while(t){
 
        ll n, m, x, y;
        cin >> n >> m >> x >> y;

        pos a1(0,0);
        pos a2(n-1,0);
        pos a3(0,m-1);
        pos a4(n-1,m-1);
        pos target(x-1,y-1);

        pos result1 = max_dist(a1, a2, a3, a4, target);
        // cout << "aqui: " << result1.x << " " << result1.y << endl;

        ll x2=-1, y2=-1, current = INT_MIN;
        if(dist(target, a1) + dist(result1, a1) > current){
            current = dist(target, a1) + dist(result1, a1);
            x2 = a1.x;
            y2 = a1.y;
        }

        if(dist(target, a2) + dist(result1, a2) > current){
            current = dist(target, a2) + dist(result1, a2);
            x2 = a2.x;
            y2 = a2.y;
        }

        if(dist(target, a3) + dist(result1, a3) > current){
            current = dist(target, a3) + dist(result1, a3);
            x2 = a3.x;
            y2 = a3.y;
        }

        if(dist(target, a4) + dist(result1, a4) > current){
            current = dist(target, a4) + dist(result1, a4);
            x2 = a4.x;
            y2 = a4.y;        
        }


        pos result2(x2,y2);
        cout << result1.x+1 << " " << result1.y+1 << " ";
        cout << result2.x+1 << " " << result2.y+1 << endl;



        t--;
    }    
    return 0;
}