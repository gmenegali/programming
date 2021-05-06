#include <iostream>
#include <cstdio>
#include <vector>

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

void print_board(vector<vi> board){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            if(board[i][j] != -1) board[i][j] = 0;
            else board[i][j] = 1;
        }
    }
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

void queen_pos(vector<vi> &queens, int pi, int pj, bool add){
    //Vertical
    for(int i=0; i<8; i++){
        if(add) queens[i][pj]++;
        else queens[i][pj]--;
    }

    //Horizontal
    for(int j=0; j<8; j++){
        
        if(add) queens[pi][j]++;    
        else queens[pi][j]--;    
    }

    int i, j;
    //SouthWest Diagonal
    i = pi; j = pj;
    while(i <= 7 and j >= 0){
        if(add) queens[i][j]++;    
        else queens[i][j]--;     
        i++;
        j--;
    }   

    //SouthEast Diagonal
    i = pi; j = pj;
    while(i <= 7 and j <= 7){
        if(add) queens[i][j]++;    
        else queens[i][j]--;
        i++;
        j++;
    }

    //NorthEast Diagonal
    i = pi; j = pj;
    while(i >= 0 and j <= 7){
        if(add) queens[i][j]++;    
        else queens[i][j]--;
        i--;
        j++;
    }

    //NorthWest Diagonal
    i = pi; j = pj;
    while(i >= 0 and j >= 0){
        if(add) queens[i][j]++;    
        else queens[i][j]--;
        i--;
        j--;
    }   

    if(add) queens[pi][pj] = -1;    
    else queens[pi][pj] = 0;
    
}
int counter = 0;
void backtracking(vector<vi> &queens, int col, vi &current, vector<vi> &solutions){
    if(col == 8){
        solutions.PB(current);
        return;
    }
    
    for(int i=0; i<8; i++){
        if(queens[i][col] == 0){
            queen_pos(queens, i, col, true);
            current[col] = i;
            backtracking(queens, col+1, current, solutions);
            queen_pos(queens, i, col, false);
        }
    }
}

vector<vi> solutions_8x8(){
    vector<vi> solutions;
    vi current(8,-1);
    vector<vi> queens(8, vector<int>(8,0));
    
    backtracking(queens, 0, current, solutions);

    return solutions;
}

int solve(vector<vi> &solutions, vector<vi> &board){
    int result = 0;
    for(auto solution : solutions){
        int partial = 0;
        for(int j=0; j<8; j++){
            partial += board[solution[j]][j];
        }
        result = max(partial, result);
    }

    return result;
}
 
int main(){
    int k, x;
    vector<vi> solutions = solutions_8x8();

    cin >> k;
    while(k){
        vector<vi> board(8, vector<int>(8,0));
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                cin >> x;
                board[i][j] = x;
            }
        }
        int result = solve(solutions, board);
        int digits = 1, result_copy = result;
        while(result_copy >= 10){
            result_copy/=10;
            digits++;
        }  
        for(int i=0; i<5-digits; i++) cout << " ";
        cout << result << endl;

        k--;
    }
 
    return 0;
}