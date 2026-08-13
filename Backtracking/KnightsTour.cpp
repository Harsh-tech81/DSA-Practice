#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};

bool isItSafe(vector<vector<int>> &grid, int i, int j, int n) {
  if (i < 0 || j < 0 || i >= n || j >= n || grid[i][j] != -1)
    return false;
  return true;
}
void display(vector<vector<int>> &grid, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << grid[i][j] << " ";
    }
    cout << endl;
  }
}

void f(vector<vector<int>> &grid, int i, int j, int n, int cnt) {
  // from i,j we can go to 8 positions
  // for every position we can only go if it is safe

  if (cnt == n * n - 1) {
    // last position
    grid[i][j] = cnt;
    display(grid, n);
    cout << endl;
    grid[i][j]=-1;
    return;
  }

  for (int m = 0; m < 8; m++) {
    int nr = i + dx[m];
    int nc = j + dy[m];
    if (isItSafe(grid, nr, nc, n)) {
      grid[i][j] = cnt;
      f(grid, nr, nc, n, cnt + 1);
      grid[i][j] = -1;  // backtracking revert the changes step 
    }
  }
}

void knightsTour(int n, int i, int j) {
  vector<vector<int>> grid(n,
                           vector<int>(n, -1)); // -1 denotes position is vacant
  f(grid, i, j, n, 0);
  cout<<endl;
}

int main() {
  int n, i, j;
  cin >> n >> i >> j;
  if (n == 2 || n == 3 || n == 4)
    cout << "No solution exists\n";
 else knightsTour(n, i, j);

  return 0;
}