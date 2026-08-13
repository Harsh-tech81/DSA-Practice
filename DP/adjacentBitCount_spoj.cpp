#include <bits/stdc++.h>
using namespace std;
int dp[105][105][3];
// this is accepted at spoj 
int helper(int n, int k, int last) {
  if (n == 0)
    return 0;
  if (n == 1 && k == 0) // the string possible are 1 and 0 both have k==0 so return 1 as the sum of the two possible in the answer 
    return 1;
  if (n == 1)
    return 0;
  if (dp[n][k][last] != -1)
    return dp[n][k][last];
  int res;
  if (last == 0)
    res = helper(n - 1, k, 0) + helper(n - 1, k, 1);  // k will never change as the last is fixed as 0 
  else
    res = helper(n - 1, k, 0) + helper(n - 1, k - 1, 1);
  return dp[n][k][last] = res;
}

int main() {
  memset(dp, -1, sizeof dp);
  int p;
  cin >> p;
  int copy = p;
  while (p--) {
    int i, n, k;
    cin >> i >> n >> k;
    cout << i << " " << helper(n, k, 0) + helper(n, k, 1) << endl; // fixed the last character as the 0 and 1 
  }

  return 0;
}