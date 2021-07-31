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
            string r,s;
            cin >> n >> r >> s;


            int ans = 0;
            for(int i=0; i<n; i++){
                if(s[i] == '1'){
                    if(i> 0 and r[i-1] == '1'){
                        r[i-1] = -1;
                        ans++;
                    }
                    else if(r[i] == '0'){
                        r[i] = -1;
                        ans++;
                    }
                    else if(i < n-1 and r[i+1] == '1'){
                        r[i+1] = -1;
                        ans++;
                    }
                }
            }

            cout << ans << endl;

            t--;
        }
    
        return 0;
    }