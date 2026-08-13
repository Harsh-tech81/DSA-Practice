#include <bits/stdc++.h>
#define ll long long int
// this Q is based on MCM(Matrix chain Multiplication) its both solution bottom up and Top Down is submitted 
using namespace std;
ll g(int i, int j, vector<ll> &v) {
  ll res = 0;
  for (int k = i; k <= j; k++) {
    res += v[k];
  }
  return res % 100;
}

ll BottomUp(vector<ll> &arr) {
  int n = arr.size();
  vector<vector<ll>> mat(105, vector<ll>(105, 0));
  for (int d = 2; d <= n; d++) {
    for (int i = 0; i <= n - d; i++) {
      int j = i + d - 1;
      ll mn = INT_MAX;
      for (int k = i; k < j; k++) {
        mn = min(mn,
                 mat[i][k] + mat[k + 1][j] + g(i, k, arr) * g(k + 1, j, arr));
      }
      mat[i][j] = mn;
    }
  }
  return mat[0][n - 1];
}

// ll f(int i, int j, vector<ll> &v, vector<vector<ll>> &dp) {
//   if (i == j)
//     return 0;
//   if (dp[i][j] != -1)
//     return dp[i][j];
//   ll mn = INT_MAX;
//   for (int k = i; k < j; k++) {
//     mn = min(mn,
//              f(i, k, v, dp) + f(k + 1, j, v, dp) + g(i, k, v) * g(k + 1, j,
//              v));
//   }
//   return dp[i][j] = mn;
// }

int main() {

  int n;
  while (cin >> n) {
    vector<ll> v(n);
    for (int i = 0; i < n; i++)
      cin >> v[i];
    // vector<vector<ll>> dp(105, vector<ll>(105, 0));
    // cout << f(0, n - 1, v, dp) << endl;
    cout << BottomUp(v) << endl;
  }

  return 0;
}