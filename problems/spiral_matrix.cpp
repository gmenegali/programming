// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
#include <iostream>
#include <vector>

using namespace std;

void print_vec(vector<int> vec){
  for(int x: vec) cout << x << " ";
  cout << endl;
}

vector<int> spiralOrder(vector<vector<int>>& matrix) {
  vector<int> result;

  int rows_steps = (int) matrix.size();
  if(rows_steps == 0) return result;
  int cols_steps = (int) matrix[0].size();

  int r=0, c=0;

  while(rows_steps > 0 and cols_steps > 0){    
    //Go Right
    for(int i=0; i < cols_steps; i++){
      result.push_back(matrix[r][c]);
      c++;
    }
    rows_steps--;
    c--;
    if(rows_steps < 1 or cols_steps < 1) break;

    //Go Down
    r++;
    for(int i=0; i < rows_steps; i++){
      result.push_back(matrix[r][c]);
      r++;
    }
    cols_steps--;
    r--;
    if(rows_steps < 1 or cols_steps < 1) break;

    //Go Left
    c--;
    for(int i=0; i < cols_steps; i++){
      result.push_back(matrix[r][c]);
      c--;
    }
    rows_steps--;
    c++;
    if(rows_steps < 1 or cols_steps < 1) break;
    cout << "r: " << r << " c: " << c << " rows_steps: " << rows_steps << " cols_steps: " << cols_steps << endl;

    //Go UP
    r--;
    for(int i=0; i < rows_steps; i++){
      result.push_back(matrix[r][c]);
      r--;
    }
    cols_steps--;
    r++;
    c++;
    if(rows_steps < 1 or cols_steps < 1) break;
  }

  return result;
}

int main(){

  vector<vector<int>> vec ={
    { 1, 2, 3, 4, 5 },
    { 6, 7, 8, 9, 10},
    {11,12,13,14, 15},
    {16,17,18,19, 20}
  };

  vector<int> result = spiralOrder(vec);
  print_vec(result);

  return 0;
}