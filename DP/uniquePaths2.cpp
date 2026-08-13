#include <bits/stdc++.h>
using namespace std;
//  top-down
// In this Q there is no need to take the vis array as there is only two
// directions movement down and right
int helper(int i, int j, vector<vector<int>> &arr, vector<vector<int>> &dp) {
  int m = arr.size();
  int n = arr[0].size();
  if (i >= m || j >= n || arr[i][j] == 1)
    return 0;
  if (i == m - 1 && j == n - 1)
    return 1;
  if (dp[i][j] != -1)
    return dp[i][j];
  int ways = helper(i + 1, j, arr, dp) + helper(i, j + 1, arr, dp);
  return dp[i][j] = ways;
}

int bottomUp(vector<vector<int>> &arr, vector<vector<long long>> &dp) {
  int m = arr.size();
  int n = arr[0].size();
  if (arr[m - 1][n - 1] != 1)
    dp[m - 1][n - 1] = 1;
  else
    return 0;
  for (int i = m - 2; i >= 0; i--) {
    if (arr[i][n - 1] != 1)
      dp[i][n - 1] = dp[i + 1][n - 1];
    else
      dp[i][n - 1] = 0;
  }
  for (int j = n - 2; j >= 0; j--) {
    if (arr[m - 1][j] != 1)
      dp[m - 1][j] = dp[m - 1][j + 1];
    else
      dp[m - 1][j] = 0;
  }
  for (int i = m - 2; i >= 0; i--) {
    for (int j = n - 2; j >= 0; j--) {
      if (arr[i][j] == 1)
        dp[i][j] = 0;
      else
        dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
    }
  }
  return dp[0][0];
}

int uniquePaths2(vector<vector<int>> &arr) {
  int m = arr.size();
  int n = arr[0].size();
  vector<vector<int>> dp(m, vector<int>(n));
  return bottomUp(arr, dp);
}

int main() {
  int m, n;
  cin >> m >> n;
  vector<vector<int>> arr(m, vector<int>(n));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
    }
  }

  cout << uniquePaths2(arr) << endl;
  return 0;
}