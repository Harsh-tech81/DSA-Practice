#include <bits/stdc++.h>
using namespace std;
int m, n;
// only solved it's premium Q on leetcode not even submitted on the coding ninja platform 
vector<vector<int>> mat;
vector<vector<int>> dir = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
void bfs(queue<pair<int, int>> &qu) {
  while (!qu.empty()) {
    auto p = qu.front();
    qu.pop();
    int i = p.first;
    int j = p.second;
    for (int d = 0; d < 4; d++) {
      int nr = i + dir[d][0];
      int nc = j + dir[d][1];
      if (nr < 0 || nc < 0 || nr >= m || nc >= n)
        continue;
      if (mat[nr][nc] != 2147483647)
        continue;
      if (mat[nr][nc] == -1)
        continue;
      mat[nr][nc] = 1 + mat[i][j];

      qu.push({nr, nc});
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    int m1, n1;
    cin >> m1 >> n1;
    vector<vector<int>> mo(m1, vector<int>(n1, 0));
    for (int i = 0; i < m1; i++) {
      for (int j = 0; j < n1; j++) {
        cin >> mo[i][j];
      }
    }
    mat = mo;
    m = mat.size();
    n = mat[0].size();
    queue<pair<int, int>> qu;
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          qu.push({i, j});
        }
      }
    }
    bfs(qu);
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        cout << mat[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
  return 0;
}