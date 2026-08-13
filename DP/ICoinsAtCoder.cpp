#include <bits/stdc++.h>
using namespace std;
// DP with probability keep this Q as important pattern
double dp[3000][1505]; // DP contain decimal values 0 to 1
double helper(vector<double> &p, int i, int x) {
  if (x == 0)
    return 1;
  if (i == -1)
    return 0;
  if (dp[i][x] > -0.9)
    return dp[i][x]; // not compare with -1 as this contain decimal values
  return dp[i][x] =
             helper(p, i - 1, x - 1) * p[i] + helper(p, i - 1, x) * (1 - p[i]);
}
int main()

{

  memset(dp, -1, sizeof dp);
  int n;
  cin >> n;
  vector<double> p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  int x = (n + 1) / 2;
  cout << fixed << setprecision(10) << helper(p, n - 1, x)
       << endl; // set the precision by using this function

  return 0;
}