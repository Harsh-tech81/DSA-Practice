#include <bits/stdc++.h>
using namespace std;
vector<int> dx = {1, 1, -1, -1, 2, 2, -2, -2};
vector<int> dy = {2, -2, 2, -2, 1, -1, 1, -1};
// this code is not submitted on coding ninja as it gives TLE for one of the
// test case 10/11 passed
// only solved it's premium Q on leetcode not even submitted on the coding ninja platform 
int x, y;
int bfs(set<pair<int, int>> &vis, queue<pair<int, int>> &qu) {
  int ans = 0;
  while (!qu.empty()) {
    int m = qu.size();
    while (m--) {
      auto p = qu.front();
      qu.pop();
      int i = p.first;
      int j = p.second;
      for (int m = 0; m < 8; m++) {
        int nr = i + dx[m];
        int nc = j + dy[m];
        if (nr == x && nc == y)
          return ans + 1;
        if (vis.count({nr, nc}))
          continue;
        qu.push({nr, nc});
        vis.insert({nr, nc});
      }
    }
    ans++;
  }
  return ans;
}
int minimumKnightMoves(int a, int b) {
  x = a;
  y = b;
  if (x == 0 && y == 0)
    return 0;
  queue<pair<int, int>> qu;
  set<pair<int, int>>
      vis; // we can't take unordered_set because it not enables pair but we
           // have used ordered set it works properly and we used set because
           // the grid position may be negative as well and there is no
           // boundation as the chessboard is infinity
  vis.insert({0, 0});
  qu.push({0, 0});
  int ans1 = bfs(vis, qu);
  return ans1;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    cout << minimumKnightMoves(a, b) << endl;
  }
  return 0;
}