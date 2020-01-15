#include <iostream>
#include <vector>

using namespace std;

int board_size = 8;
bool found = false;

vector<vector<int>> place_queen(vector<vector<int>> board, int r, int c){
  //Mark the column
  for(int i=0; i<board_size; i++) board[i][c] = 1;

  //Mark the row
  for(int i=0; i<board_size; i++) board[r][i] = 1;

  //Mark the diagonal 45 degree down
  int r_copy = r;
  int c_copy = c;
  while(r_copy >= 0 and c_copy >= 0 and r_copy < board_size and c_copy < board_size ){
    board[r_copy][c_copy] = 1;
    r_copy++;
    c_copy--;
  }

  //Mark the diagonal 45 degree up
  r_copy = r;
  c_copy = c;
  while(r_copy >= 0 and c_copy >= 0 and r_copy < board_size and c_copy < board_size ){
    board[r_copy][c_copy] = 1;
    r_copy--;
    c_copy++;
  }

  //Mark the diagonal 135 degree down
  r_copy = r;
  c_copy = c;
  while(r_copy >= 0 and c_copy >= 0 and r_copy < board_size and c_copy < board_size ){
    board[r_copy][c_copy] = 1;
    r_copy++;
    c_copy++;
  }

  //Mark the diagonal 135 degree up
  r_copy = r;
  c_copy = c;
  while(r_copy >= 0 and c_copy >= 0 and r_copy < board_size and c_copy < board_size ){
    board[r_copy][c_copy] = 1;
    r_copy--;
    c_copy--;
  }  

  board[r][c] = 9; // Place the queen
  return board;
}

void print_board(vector<vector<int>> board){
  cout << "Board:" << endl;
  for(int i=0; i<board_size; i++){
    for(int j=0; j<board_size; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

bool check_board(vector<vector<int>> board){
  int queen_counter=0; 
  for(int i=0; i<board_size; i++){
    for(int j=0; j<board_size; j++){
      if(board[i][j] == 9) queen_counter++;
    }
  }
  if(queen_counter == board_size) return true;
  else return false;
}

void distrib_queens(vector<vector<int>> board, int row){
  if(check_board(board)){ //Found Solution
    print_board(board);
    found = true;
  }
  else if(found == false){
    for(int i=0; i<board_size; i++){
      if(board[row][i] == 0){ // Can place a queen
        vector<vector<int>> new_board = place_queen(board, row, i);
        distrib_queens(new_board, row+1);
      }
    }
  }
}

int main(){
  vector<vector<int>> board(board_size);
  for(int i=0; i < board_size; i++) board[i].resize(board_size,0);
  distrib_queens(board, 0);

  return 0;
}