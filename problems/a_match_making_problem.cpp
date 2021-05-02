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
    int b, s, count=1;

    while(cin >> b >> s){
        if(b ==0 and s==0)
            break;
        
        int x;
        vi men;
        vi women;
 
        for(int i=0; i<b; i++){
            cin >> x;
            men.PB(x);
        }

        for(int i=0; i<s; i++){
            cin >> x;
            women.PB(x);
        }

        sort(men.begin(), men.end());
        int diff = (int) (men.size() - women.size());

        cout << "Case " << count << ": ";
        if(diff > 0){
            cout << diff << " " << men[0] << endl;
        }
        else{
            cout << 0 << endl;
        }
        count++;


    }
 
    return 0;
}