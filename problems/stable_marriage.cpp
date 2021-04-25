#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
 
using namespace std;
typedef vector<int> vi; 
 
int main(){
    int t;
 
    cin >> t;
    while(t){
 
        int n, x;
        cin >> n;
        vector<vi> w(n,vi(n,0));
        vector<vi> m(n,vi(n,0));
        vector<vi> women_inverted(n,vi(n,0));

        for(int i=0; i<2*n; i++){
            for(int j=0; j<=n; j++){
                cin >> x;
                if(j>0){
                    if(i<n){
                        w[i][j-1] = x-1;
                        women_inverted[i][x-1] = j-1;
                    }
                    else{
                        m[i-n][j-1] = x-1;
                    }
                }
            }
        }

        queue<int> free_men;
        for(int i=0; i<n; i++){
            free_men.push(i);
        }

        vi husbands(n,-1); 
        vi wifes(n,-1); 
        vi count(n,0); 

        while(!free_men.empty()){
            int current_man = free_men.front();
            for(int i=count[current_man]; i<n; i++){
                int current_woman = m[current_man][i];
                if(wifes[current_man] == -1 and husbands[current_woman] == -1){
                    husbands[current_woman] = current_man;
                    wifes[current_man] = current_woman;
                    break;
                }
                else if(wifes[current_man] == -1 and husbands[current_woman] != -1){ //Does the woman wanna change the husband?
                    int current_husband = husbands[current_woman];
                    if(women_inverted[current_woman][current_man] < women_inverted[current_woman][current_husband]){
                        wifes[current_husband] = 0;
                        free_men.push(current_husband);
                        husbands[current_woman] = current_man;
                        wifes[current_man] = current_woman;
                    }
                }
            }
            free_men.pop();
            count[current_man]++;
        }

        for(int i=0; i<n; i++){
            cout << i+1 << " " << wifes[i]+1 << endl;
        }
 
        t--;
    }
 
    return 0;
}