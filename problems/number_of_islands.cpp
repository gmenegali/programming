// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. 
// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
// You may assume all four edges of the grid are all surrounded by water.
#include <iostream>
#include <vector>

using namespace std;

void print_grid(vector<vector<char>> &grid){
  for(int i=0; i<(int) grid.size(); i++){
    for(int j=0; j<(int) grid[i].size(); j++) cout << grid[i][j] << " ";
    cout << endl;
  }
}

void mark_explored(vector<vector<char>>& grid, int row, int column){
  if(grid[row][column] == '1') grid[row][column] = '2'; //Mark

  //Explore the island
  if(row < (int) grid.size() -1 and grid[row+1][column] == '1') //Go Down
    mark_explored(grid, row+1, column);
  if(row > 0 and grid[row-1][column] == '1') //Go Up
    mark_explored(grid, row-1, column);
  if(column < (int) grid[0].size() -1 and grid[row][column+1] == '1') //Go Right
    mark_explored(grid, row, column+1);
  if(column > 0 and grid[row][column-1] == '1') //Go Left
    mark_explored(grid, row, column-1);
}

int numIslands(vector<vector<char>>& grid){
  int count = 0;
  for(int i=0; i<(int) grid.size(); i++){
    for(int j=0; j<(int) grid[i].size(); j++){
      if(grid[i][j] == '1'){ //Find land unexplored
        count++;
        mark_explored(grid, i, j);
      }
    }
  }
  return count;
}


int main(){

  vector<vector<char>> grid = {{'1','1','1'},{'0','1','0'},{'1','1','1'}};
  // print_grid(grid);
  int ans = numIslands(grid);
  cout << ans << endl;


  return 0;
}