#include <iostream>
#include <cstdio>
#include <bits/stdc++.h>
 
#define ll long long int
 
using namespace std;
 
template <class vector_type>
void printVec(vector<vector_type> &v){
    for(int i=0; i < (int) v.size(); i++){
        cout << v[i] << ' ';
    }
    cout << endl;
}
 
int main(){
    int t, n;
    string s;
    vector<int> testCase;
 
    cin >> t;
    while(t){
        cin >> n >> s;
        int count = 0;
        size_t pos = s.find("abacaba");
        while( pos != string::npos){
            count++;
            pos = s.find("abacaba", 1+pos);
        }
        if(count < 1){
            for(int i=0; i<=(int)s.size()-7; i++){
                if((s[i] == 'a' or s[i] == '?') and
                (s[i+1] == 'b' or s[i+1] == '?') and
                (s[i+2] == 'a' or s[i+2] == '?') and
                (s[i+3] == 'c' or s[i+3] == '?') and
                (s[i+4] == 'a' or s[i+4] == '?') and
                (s[i+5] == 'b' or s[i+5] == '?') and
                (s[i+6] == 'a' or s[i+6] == '?')
                ){
                    if((int) s.size() >= 11 and i<=(int) s.size()-11){
                        if(
                            s[i+7] == 'c' and
                            s[i+8] == 'a' and
                            s[i+9] == 'b' and
                            s[i+10] == 'a'
                        ){
                            if(s[i] == '?')
                                s[i] = 'd';
                            if(s[i+1] == '?')
                                s[i+1] = 'd';
                            if(s[i+2] == '?')
                                s[i+2] = 'd';
                            if(s[i+3] == '?')
                                s[i+3] = 'd';
                            if(s[i+4] == '?')
                                s[i+4] = 'd';
                            if(s[i+5] == '?')
                                s[i+5] = 'd';
                            if(s[i+6] == '?')
                                s[i+6] = 'd';
                            continue;
                        }
                    }
                    s[i] = 'a';
                    s[i+1] = 'b';
                    s[i+2] = 'a';
                    s[i+3] = 'c';
                    s[i+4] = 'a'; 
                    s[i+5] = 'b';
                    s[i+6] = 'a';
                    count++;
                    pos = s.find("?");
                    while( pos != string::npos){
                        s[pos] = 'd';
                        pos = s.find("?", 1+pos);
                    }
                    break;
                }
            }
        }
        
        if( count != 1){
            cout << "No" << endl;
        }
        else{
            pos = s.find("?");
            while( pos != string::npos){
                s[pos] = 'd';
                pos = s.find("?", 1+pos);
            }
            cout << "Yes" << endl << s << endl;
        }
        
        t--;
    }
    
    return 0;
}