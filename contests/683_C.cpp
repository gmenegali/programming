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
            vector<ll> testCase;
            vector<int> ans;
            
            int n;
            ll W, current=0, x;
            cin >> n >> W;

            bool solved = false;
            for(int i=0; i<n; i++){
                cin >> x;
                testCase.PB(x);
                if(x >= W/2 + (W%2 != 0) and x <= W and !solved){
                    solved = true;
                    cout << 1 << endl;
                    cout << i+1 << endl;
                }
            }

            if(!solved){
                for(int i=0; i<n; i++){
                    if(testCase[i] <= W){
                        current += testCase[i];
                        ans.PB(i);
                    }
                    if(current >= W/2 + (W%2 != 0)){
                        solved = true;
                        break;
                    }
                }

                if(solved){
                    cout << (int) ans.size() << endl;
                    for(int i=0; i<(int)ans.size(); i++){
                        cout << ans[i]+1 << " ";
                    }
                    cout << endl;
                }
                else{
                    cout << -1 << endl;
                }
            }


            t--;
        }
    
        return 0;
    }