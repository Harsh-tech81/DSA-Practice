#include <bits/stdc++.h>
using namespace std;
// hackerearth problem
// This is k-ordered LCS which means I can chaneg the elements of the array 1 at
// most K times then find the longest common subsequence
// This code is accepted and use of the 3-D DP..
int helper(vector<int> &v, vector<int> &v1, int i1, int i2, int k,
           vector<vector<vector<int>>> &dp) {
  int n = v.size();
  int m = v1.size();
  if (i1 >= n || i2 >= m)
    return 0;
  if (dp[i1][i2][k] != -1)
    return dp[i1][i2][k];
  int ans;
  if (v[i1] == v1[i2]) {
    ans = 1 + helper(v, v1, i1 + 1, i2 + 1, k, dp);
  } else {
    if (k > 0) {
      ans = max({1 + helper(v, v1, i1 + 1, i2 + 1, k - 1, dp),
                 helper(v, v1, i1 + 1, i2, k, dp),
                 helper(v, v1, i1, i2 + 1, k, dp)});
    } else {
      ans = max(helper(v, v1, i1 + 1, i2, k, dp),
                helper(v, v1, i1, i2 + 1, k, dp));
    }
  }
  return dp[i1][i2][k] = ans;
}

int main() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<int> v(n), v1(m);
  for (int i = 0; i < n; i++)
    cin >> v[i];
  for (int i = 0; i < m; i++)
    cin >> v1[i];
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
  cout << helper(v, v1, 0, 0, k, dp) << endl;
  return 0;
}