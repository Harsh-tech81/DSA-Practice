#include <bits/stdc++.h>
using namespace std;
// Bitmask DP is used as the second paramter is set so to use the set we have used the Bitmask representation
int dp[5][1 << 5];
int grid[4][4] = {
    {0, 20, 42, 25}, {20, 20, 30, 34}, {42, 30, 0, 10}, {25, 34, 10, 0}};
int tsp(int curr, int mask, int n) {
  if (mask == ((1 << n) - 1))
    return grid[curr][0];  // if all the nodes are visited then at last add the return value to the zero from the curr Node
  if (dp[curr][mask] != -1)
    return dp[curr][mask];
  int ans = INT_MAX;
  for (int neig = 0; neig < n; neig++) {   // Time Complexity is O(n^2 * 2^n)
    if ((mask & (1 << neig)) == 0) {  // if the node is not visited 
      ans = min(ans, grid[curr][neig] + tsp(neig, mask | (1 << neig), n));
    }
  }
  return dp[curr][mask] = ans;
}
int main() {
  memset(dp, -1, sizeof dp);
  cout << tsp(0, 1, 4) << endl;  // initially starts from the 0th Node and mark visited 0001 as the integer val is 1 

  return 0;
}