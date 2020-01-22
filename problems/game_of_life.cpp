// According to the Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
// Given a board with m by n cells, each cell has an initial state live (1) or dead (0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
// Any live cell with fewer than two live neighbors dies, as if caused by under-population.
// Any live cell with two or three live neighbors lives on to the next generation.
// Any live cell with more than three live neighbors dies, as if by over-population..
// Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
// Write a function to compute the next state (after one update) of the board given its current state. The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously.
#include <iostream>
#include <vector>

using namespace std;

void print_board(vector<vector<int>> &board){
  for(vector<int> line : board){
    for(int elem : line) cout << elem << " ";
    cout << endl;
  }
  cout << endl;
}

int count_live_neighbors(vector<vector<int>>& board, int row, int col) {
  int board_row_size = (int) board.size();
  int board_col_size = (int) board[0].size();
  int count = 0;

  if(row+1 < board_row_size and board[row+1][col] > 0) count++;
  if(row+1 < board_row_size and col+1 < board_col_size and board[row+1][col+1] > 0) count++;
  if(col+1 < board_col_size and board[row][col+1] > 0) count++;
  if(row > 0 and board[row-1][col] > 0) count++;
  if(col > 0 and board[row][col-1] > 0) count++;
  if(row > 0 and col > 0 and board[row-1][col-1] > 0) count++;
  if(col > 0 and row+1 < board_row_size and board[row+1][col-1] > 0) count++;
  if(row > 0 and col+1 < board_col_size and board[row-1][col+1] > 0) count++;

  return count;
}

/**
 * The sign of the number indicated the state before the new round ('+' was alive, '-' was dead)
 * 
 * Dead -> Live = '-1'
 * Live -> Dead  = '+2'
 */
void gameOfLife(vector<vector<int>>& board) {
  int board_row_size = (int) board.size();
  int board_col_size = (int) board[0].size();

  for(int i=0; i<board_row_size; i++){
    for(int j=0; j<board_col_size; j++){
      int num_neighbors = count_live_neighbors(board, i, j);
      
      //Live -> Die
      if(num_neighbors < 2 or num_neighbors > 3){
        if(board[i][j] == 1) board[i][j] = 2;
      }

      //Dead -> Live
      else if(num_neighbors == 3){
        if(board[i][j] == 0) board[i][j] = -1;
      }
    }
  }

  for(int i=0; i<board_row_size; i++){
    for(int j=0; j<board_col_size; j++){
      if(board[i][j] == 2) board[i][j] = 0;
      if(board[i][j] == -1) board[i][j] = 1;
    }
  }

}


int main(){
  vector<vector<int>> board = {
    {0,1,0},
    {0,0,1},
    {1,1,1},
    {0,0,0}
  };
  print_board(board);
  gameOfLife(board);
  print_board(board);



  return 0;
}