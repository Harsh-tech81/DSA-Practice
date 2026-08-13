#include <bits/stdc++.h>
using namespace std;
// MCM problem 
// Bottom Up some bit different from the other bottom up solutions 
int matrixMultiplication(vector<int> &arr) {
  int n = arr.size();
  vector<vector<int>> mat(n, vector<int>(n, 0));
  for (int d = 1; d < n - 1; d++) {
    for (int i = 1; i < n - d; i++) {
      int j = i + d;
      int mn = INT_MAX;
      for (int k = i; k < j; k++) {
        mn = min(mn,mat[i][k] + mat[k + 1][j] + arr[i - 1] * arr[k] * arr[j]);
      }
      mat[i][j]=mn;
    }
  }
  return mat[1][n - 1];
}

// Top-Down Approach
int f(int i, int j, vector<int> &v, vector<vector<int>> &dp) {
  if (i == j || abs(i - j) == 1)
    return 0;
  if (dp[i][j] != -1)
    return dp[i][j];
  int mn = INT_MAX;
  for (int k = i + 1; k < j; k++) {
    mn = min(mn, f(i, k, v, dp) + f(k, j, v, dp) + v[i] * v[k] * v[j]);
  }
  return dp[i][j] = mn;
}

int main() {
  vector<int> v = {1, 2, 3, 4, 3};
    cout << matrixMultiplication(v) << endl;
  int n = v.size();
  vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
//   cout << f(0, n - 1, v, dp) << endl;
  return 0;
}