// Given a 2D board and a word, find if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.
#include <iostream>
#include <vector>

using namespace std;

void print_board(vector<vector<char>>& board){
  for(vector<char> line : board){
    for(char c : line){
      cout << c << " ";
    }
    cout << endl;
  }
}

bool explorer(vector<vector<char>> &board, int row, int col, string word){        
  char target = word[0];
  bool result = false;
  
  string next_word = word;
  if(next_word != "") next_word.erase(next_word.begin());

  int board_rows = (int) board.size();
  int board_cols = (int) board[0].size();

  if(board[row][col] == target){
    if(next_word == "") return true; //Base case
    
    //Mark the used path
    if(board[row][col] >= 'A' and board[row][col] <= 'Z') board[row][col] += 32;
    else board[row][col] -= 32; 

    //Try the neighbors
    if(row+1 < board_rows and result == false) result = explorer(board, row+1, col, next_word);
    if(col+1 < board_cols and result == false) result = explorer(board, row, col+1, next_word);
    if(row > 0 and result == false) result = explorer(board, row-1, col, next_word);
    if(col > 0 and result == false) result = explorer(board, row, col-1, next_word);
    if(result == true) return result;

    //Unmark the used path
    if(board[row][col] >= 'A' and board[row][col] <= 'Z') board[row][col] += 32;
    else board[row][col] -= 32; 
  }
  
  return result;
}

bool exist(vector<vector<char>>& board, string word){
  bool result = false;
  for(int r=0; r<(int)board.size(); r++){
    for(int c=0; c<(int)board[r].size(); c++){
      if(board[r][c] == word[0]) result = explorer(board, r, c , word);
      if(result == true) return result;
    }
  }
  return result;
}

int main(){  
  string word = "ABCCFB";
  vector<vector<char>> board = {
    {'A','B','C','E'},
    {'S','F','C','S'},
    {'A','D','E','E'}
  };

  if(exist(board, word)) cout << "Exist" << endl;
  else cout << "Don't exist" << endl;

  return 0;
}