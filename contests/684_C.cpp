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
        cout << v[i]+1 << ' ';
    }
    cout << endl;
}



vector<vi> test(vector<vi> &matrix, int i, int j){
    int count = matrix[i][j]+ matrix[i][j+1] + matrix[i+1][j] + matrix[i+1][j+1]; 
    int target1 = 0, target0 = 0;
    vector<vi> result;
    vi temp;
    if(count == 4){
        target1 = 3;
        target0 = 0;
        temp.clear();

        if(matrix[i][j] == 1 and target1 > 0){
            matrix[i][j] = 0;
            temp.PB(i);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i][j] == 0 and target0 > 0){
            matrix[i][j] = 1;
            temp.PB(i);
            temp.PB(j);
            target0--;
        }

        if(matrix[i+1][j] == 1 and target1 > 0){
            matrix[i+1][j] = 0;
            temp.PB(i+1);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i+1][j] == 0 and target0 > 0){
            matrix[i+1][j] = 1;
            temp.PB(i+1);
            temp.PB(j);
            target0--;
        }

        if(matrix[i][j+1] == 1 and target1 > 0){
            matrix[i][j+1] = 0;
            temp.PB(i);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i][j+1] == 0 and target0 > 0){
            matrix[i][j+1] = 1;
            temp.PB(i);
            temp.PB(j+1);
            target0--;
        }
        
        if(matrix[i+1][j+1] == 1 and target1 > 0){
            matrix[i+1][j+1] = 0;
            temp.PB(i+1);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i+1][j+1] == 0 and target0 > 0){
            matrix[i+1][j+1] = 1;
            temp.PB(i+1);
            temp.PB(j+1);
            target0--;
        }
        result.PB(temp);
        count = 1;
    }
    if(count == 1){
        target1 = 1;
        target0 = 2;
        temp.clear();

        if(matrix[i][j] == 1 and target1 > 0){
            matrix[i][j] = 0;
            temp.PB(i);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i][j] == 0 and target0 > 0){
            matrix[i][j] = 1;
            temp.PB(i);
            temp.PB(j);
            target0--;
        }

        if(matrix[i+1][j] == 1 and target1 > 0){
            matrix[i+1][j] = 0;
            temp.PB(i+1);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i+1][j] == 0 and target0 > 0){
            matrix[i+1][j] = 1;
            temp.PB(i+1);
            temp.PB(j);
            target0--;
        }

        if(matrix[i][j+1] == 1 and target1 > 0){
            matrix[i][j+1] = 0;
            temp.PB(i);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i][j+1] == 0 and target0 > 0){
            matrix[i][j+1] = 1;
            temp.PB(i);
            temp.PB(j+1);
            target0--;
        }
        
        if(matrix[i+1][j+1] == 1 and target1 > 0){
            matrix[i+1][j+1] = 0;
            temp.PB(i+1);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i+1][j+1] == 0 and target0 > 0){
            matrix[i+1][j+1] = 1;
            temp.PB(i+1);
            temp.PB(j+1);
            target0--;
        }
        result.PB(temp);

        count = 2;
    }

    if(count == 2){
        target1 = 1;
        target0 = 2;

        temp.clear();

        if(matrix[i][j] == 1 and target1 > 0){
            matrix[i][j] = 0;
            temp.PB(i);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i][j] == 0 and target0 > 0){
            matrix[i][j] = 1;
            temp.PB(i);
            temp.PB(j);
            target0--;
        }

        if(matrix[i+1][j] == 1 and target1 > 0){
            matrix[i+1][j] = 0;
            temp.PB(i+1);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i+1][j] == 0 and target0 > 0){
            matrix[i+1][j] = 1;
            temp.PB(i+1);
            temp.PB(j);
            target0--;
        }

        if(matrix[i][j+1] == 1 and target1 > 0){
            matrix[i][j+1] = 0;
            temp.PB(i);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i][j+1] == 0 and target0 > 0){
            matrix[i][j+1] = 1;
            temp.PB(i);
            temp.PB(j+1);
            target0--;
        }
        
        if(matrix[i+1][j+1] == 1 and target1 > 0){
            matrix[i+1][j+1] = 0;
            temp.PB(i+1);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i+1][j+1] == 0 and target0 > 0){
            matrix[i+1][j+1] = 1;
            temp.PB(i+1);
            temp.PB(j+1);
            target0--;
        }
        result.PB(temp);
        
        count = 3;
    }
    if(count == 3){
        target1 = 3;
        target0 = 0;

        temp.clear();

        if(matrix[i][j] == 1 and target1 > 0){
            matrix[i][j] = 0;
            temp.PB(i);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i][j] == 0 and target0 > 0){
            matrix[i][j] = 1;
            temp.PB(i);
            temp.PB(j);
            target0--;
        }

        if(matrix[i+1][j] == 1 and target1 > 0){
            matrix[i+1][j] = 0;
            temp.PB(i+1);
            temp.PB(j);
            target1--;
        }
        else if(matrix[i+1][j] == 0 and target0 > 0){
            matrix[i+1][j] = 1;
            temp.PB(i+1);
            temp.PB(j);
            target0--;
        }

        if(matrix[i][j+1] == 1 and target1 > 0){
            matrix[i][j+1] = 0;
            temp.PB(i);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i][j+1] == 0 and target0 > 0){
            matrix[i][j+1] = 1;
            temp.PB(i);
            temp.PB(j+1);
            target0--;
        }
        
        if(matrix[i+1][j+1] == 1 and target1 > 0){
            matrix[i+1][j+1] = 0;
            temp.PB(i+1);
            temp.PB(j+1);
            target1--;
        }
        else if(matrix[i+1][j+1] == 0 and target0 > 0){
            matrix[i+1][j+1] = 1;
            temp.PB(i+1);
            temp.PB(j+1);
            target0--;
        }
        result.PB(temp);
    }

    return result;
    
}
 
int main(){
    int t;
 
    cin >> t;
    while(t){
        vector<int> testCase;
        int n, m;
        string s;
        cin >> n >> m;
        vector<vi> matrix(n, vector<int>(m));
        
        for(int i=0; i<n; i++){
            cin >> s;
            for(int j=0; j<m; j++){
                if(s[j] == '1'){
                    matrix[i][j] = 1;
                }
                else{
                    matrix[i][j] = 0;
                }
            }
        }
        vector<vector<vi>> result;
        for(int i=0; i<n; i+=2){
            for(int j=0; j<m; j+=2){
                if(n%2 == 0 and m%2 == 0){
                    result.PB(test(matrix, i, j));
                }
                else if(n%2 == 0 and m%2 !=0){
                    if(j != m-1){
                        result.PB(test(matrix, i, j));
                    }
                    else{
                        result.PB(test(matrix, i, j-1));
                    }
                }
                else if(n%2 != 0 and m%2 ==0){
                    if(i != n-1){
                        result.PB(test(matrix, i, j));
                    }
                    else{
                        result.PB(test(matrix, i-1, j));
                    }
                }
                else{
                    if(i != n-1 and j != m-1){
                        result.PB(test(matrix, i, j));
                    }
                    else if(i == n-1 and j != m-1){
                        result.PB(test(matrix, i-1, j));
                    }
                    else if(i != n-1 and j == m-1){
                        result.PB(test(matrix, i, j-1));
                    }
                    else{
                        result.PB(test(matrix, i-1, j-1));
                    }
                }
            }
        }

        int num = 0;
        for(auto mat : result){
            num += (int)mat.size();
        }
        cout << num << endl;
        
        for(auto mat : result){
            for(auto line : mat){
                printVec(line);
            }
        }

        t--;
    }
 
    return 0;
}