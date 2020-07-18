#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
 
void print_matrix(vector<vector<int>> &matrix){
  for(int i=0; i < (int) matrix.size(); i++){
    for(int j=0; j < (int) matrix[i].size(); j++){
      cout << matrix[i][j];
    }
    cout << endl;
  }
}

int f(vector<int> row, vector<int> col){
  int row_max=INT_MIN, row_min=INT_MAX, col_max=INT_MIN, col_min=INT_MAX;
  for(int i=0; i < (int)row.size(); i++){
    if(row[i] > row_max) row_max = row[i];
    if(row[i] < row_min) row_min = row[i];
    if(col[i] > col_max) col_max = col[i];
    if(col[i] < col_min) col_min = col[i];
  }
  return (pow(row_max - row_min, 2) + pow(col_max - col_min, 2));
}

void grid(int n, int k){
  vector<vector<int>> matrix(n, vector<int>(n));
  vector<int> col(n);
  vector<int> row(n);

  int r=0, c=0, c_initializer=1;
  for(int i=0; i<k; i++){
    matrix[r][c] = 1;
    row[r]++;
    col[c]++;

    r++;
    c++;
    if(r == n){
      r %= n;
      c = c_initializer;
      c_initializer++;
    }
    if(c == n){
      c %= n;
    }
  }
  cout << f(row, col) << endl;
  print_matrix(matrix);
}

int main(){
  int t, n, k;
  cin >> t;
  while(t){
    cin >> n >> k;
    grid(n, k);
    t--;
  }
  
  return 0;
}