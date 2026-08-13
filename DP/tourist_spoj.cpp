#include <bits/stdc++.h>
#define ll long long int
using namespace std;
// this code is submitted 
ll n, m;            // dimensions of the matrix
char mat[105][105]; // input matrix
ll dp[105][105][105];

ll f(ll i, ll j, ll x, ll y) {
  if (i > m || j > n || x > m || y > n || mat[i][j] == '#' || mat[x][y] == '#')
    return 0; // assume 1-based indexing
  if (i == m && j == n)
    return mat[i][j] == '*';  // Is the tourist 1 already at the n,m i.e., (i+j)==(n+m) 
  if (dp[i][j][x] != -1)
    return dp[i][j][x];
  ll res = INT_MIN;
  res = max(res, f(i + 1, j, x + 1, y));
  res = max(res, f(i + 1, j, x, y + 1));
  res = max(res, f(i, j + 1, x + 1, y));
  res = max(res, f(i, j + 1, x, y + 1));
  res += (mat[i][j] == '*');
  res += (mat[x][y] == '*');

  // repetitive counting
  if (i == x && j == y && mat[i][j] == '*')
    res--;
  return dp[i][j][x] = res;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> mat[i][j];
      }
    }

    cout << f(1, 1, 1, 1) << endl;
  }
  return 0;
}