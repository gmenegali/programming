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
        
        vector<string> v = {
            "1", "11", "111", "1111",
            "2", "22", "222", "2222",
            "3", "33", "333", "3333",
            "4", "44", "444", "4444",
            "5", "55", "555", "5555",
            "6", "66", "666", "6666",
            "7", "77", "777", "7777",
            "8", "88", "888", "8888",
            "9", "99", "999", "9999",
        };


        cin >> t;
        while(t){
            vector<int> testCase;
            string x;
            cin >> x;

            int result = 0;
            for(int i=0; i<(int) v.size(); i++){
                if(v[i] == x){
                    result += (int) v[i].size();
                    break;
                }
                else{
                    result += (int) v[i].size();
                }
            }

            cout << result << endl;
            t--;
        }
    
        return 0;
    }