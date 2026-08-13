#include <bits/stdc++.h>
using namespace std;
#define ll long int
// This is accepted at the spoj platform 2D DP solution is accepted 3D is going to give wrong answer for some large test cases because this 
vector<ll> cap, ass;
ll size;

// ll helper(int i, int x) { // x is assistant-captain
//   if (i >= size)
//     return 0;
//   if (dp[i][x] != -1)
//     return dp[i][x];
//   if (x == 0) {
//     return dp[i][x] = ass[i] + helper(i + 1, x + 1);
//   } else if (x == size - i) {
//     return dp[i][x] = cap[i] + helper(i + 1, x - 1);
//   } else {
//     return dp[i][x] = min(cap[i] + helper(i + 1, x - 1),
//                           ass[i] + helper(i + 1, x + 1));
//   }
// }

// Now solve by using 3D DP
// 3D DP code is not able to submitted 
ll helper(int i, int c, int a,
          vector<vector<vector<int>>> &dp) { // x is assistant-captain
  if (i >= size)
    return 0;
  if (dp[i][c][a] != -1)
    return dp[i][c][a];
  if (c == a) {
    return dp[i][c][a] = ass[i] + helper(i + 1, c, a + 1, dp);
  } else if (a - c == size - i) {
    return dp[i][c][a] = cap[i] + helper(i + 1, c + 1, a - 1, dp);
  } else {
    return dp[i][c][a] = min(cap[i] + helper(i + 1, c + 1, a, dp),
                             ass[i] + helper(i + 1, c, a + 1, dp));
  }
}

int main() {
  ll n;
  cin >> n;
  size = n;
  vector<vector<vector<int>>> dp(
      n + 1, vector<vector<int>>(n / 2 + 1, vector<int>(n / 2 + 1, -1)));
  while (n--) {
    ll x, y;
    cin >> x >> y;
    cap.push_back(x);
    ass.push_back(y);
  }

  cout << ass[0] + helper(1, 0, 1, dp) << endl;
  return 0;
}