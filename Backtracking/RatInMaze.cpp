#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
int m;
vector<vector<bool>> vis;
// Do it itself proud yourself 
void helper(int i, int j, string str, vector<vector<int>> &maze) {
  if (i < 0 || j < 0 || i >= m || j >= m || vis[i][j] || maze[i][j] == 0) // skipping the pruned path 
    return;
  if (i == m - 1 && j == m - 1) {
    ans.push_back(str);
    return;
  }
  vis[i][j] = 1;
  helper(i + 1, j, str + 'D', maze);  // lexicographically smallest order.(automatically Handled)
  helper(i, j - 1, str + 'L', maze);
  helper(i, j + 1, str + 'R', maze);
  helper(i - 1, j, str + 'U', maze);
  vis[i][j] = 0;  // after recursive call what we've do it is basically during Backtracking step 
  str.pop_back();
}
vector<string> ratInMaze(vector<vector<int>> &maze) {
  helper(0, 0, "", maze);
  return ans;
}
int main() {
  int n;
  cin >> n;
  vector<vector<int>> v(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> v[i][j];
    }
  }

  m = n;
  vis.resize(n, vector<bool>(n, 0));
  vector<string> ans1 = ratInMaze(v);
  for (auto x : ans1) {
    cout << x << " ";
  }
  cout << endl;
  return 0;
}
