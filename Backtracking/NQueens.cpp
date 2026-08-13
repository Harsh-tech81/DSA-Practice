#include <bits/stdc++.h>
using namespace std;
vector<vector<char>> grid;
bool canPlaceQueen(int row, int col, int n) {
  // Column Check
  for (int i = row - 1; i >= 0; i--) {
    if (grid[i][col] == 'Q')
      return false; // we are attacked
  }
  // Left Diagonal Check
  for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
    if (grid[i][j] == 'Q')
      return false; // we are attacked
  }
  // Right Diagonal Check
  for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
    if (grid[i][j] == 'Q')
      return false; // we are attacked
  }
  return true; // there is no attack (row,col,diagonal)
}

void f(int row, int n) {
  if (row == n) {
    // we got one possible way
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        cout << grid[i][j];
      }
      cout << endl;
    }
    cout<<endl;
    return;
  }
  for (int col = 0; col < n; col++) {
    if (canPlaceQueen(row, col, n)) {
      grid[row][col] = 'Q';
      f(row + 1, n);
      grid[row][col] = '.';
    }
  }
}

void solveNQueens(int n) {
  grid.resize(n, vector<char>(n, '.'));
  f(0, n);
}

int main() {
  int n;
  cin >> n;
  solveNQueens(n);

  return 0;
}