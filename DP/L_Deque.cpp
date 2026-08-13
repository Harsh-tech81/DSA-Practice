#include <bits/stdc++.h>
using namespace std;
#define ll long long int
// not able to understand its Bottom-up code 
// AtCoder Q
// long long helper(long long i, long long j, vector<long long> &v,
//                  vector<vector<long long>> &dp) {
//   if (i == j)
//     return v[i];
//   if (dp[i][j] != -1)
//     return dp[i][j];
//   return dp[i][j] = max(v[i] - helper(i + 1, j, v, dp),
//                         v[j] - helper(i, j - 1, v, dp));
// }

ll BottomUp(vector<ll> &v) {
  int n = v.size();
  vector<vector<ll>> dp(3005, vector<ll>(3005, 0));
  for (int i = 0; i < n; i++)  // when i and j both are equal base case 
    dp[i][i] = v[i];
  for (int d = 2; d <= n; d++) {
    for (int i = 0; i <= n - d; i++) {
      int j = i + d - 1;
      dp[i][j] =
          max(v[i] - dp[i + 1][j], v[j] - dp[i][j-1]);
    }
  }
  return dp[0][n - 1];
}

int main() {
  long long n;
  cin >> n;
  vector<ll> v(n);
  //   vector<vector<long long>> dp(3005, vector<long long>(3005, -1));
  for (ll i = 0; i < n; i++)
    cin >> v[i];
  cout << BottomUp(v);

  return 0;
}