#include <bits/stdc++.h>
using namespace std;
// This code is submitted on the AtCoder
int dp[22][1 << 22];
int mod = 1e9 + 7;
int f(int row, int mask, int n, vector<vector<int>> &mat) {
  if (row >= n + 1) {
    if (mask == 0) // one possible way
      return 1;
    return 0;
  }
  if (dp[row][mask] != -1)
    return dp[row][mask];
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    bool aval = mask & (1 << (i - 1));
    if (aval && mat[row][i] == 1) {
      ans =
          ((ans % mod) + (f(row + 1, (mask ^ (1 << (i - 1))), n, mat)) % mod) %
          mod;
    }
  }
  return dp[row][mask] = ans % mod;
}

int main() {
  int n;
  cin >> n;
  memset(dp, -1, sizeof dp);
  vector<vector<int>> mat(n + 1, vector<int>(n + 1)); // compatibility matrix
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> mat[i][j];
    }
  }
  cout << f(1, (1 << n) - 1, n, mat) << endl;

  return 0;
}