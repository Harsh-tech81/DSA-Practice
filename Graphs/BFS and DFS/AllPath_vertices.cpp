#include <iostream>
#include <list>
#include <unordered_set>
#include <vector>

using namespace std;
vector<list<int>> graph; // array of list
int v;                   // No. of Vertices
vector<vector<int>> result;
unordered_set<int> visited;
void add_edge(int src, int dest, bool bi_dir = true) {
  graph[src].push_back(dest);
  if (bi_dir) {
    graph[dest].push_back(src);
  }
}
void dfs(int curr, int end, vector<int> &path) {
  if (curr == end) {
    path.push_back(curr);
    result.push_back(path);
    path.pop_back();
    return;
  }
  visited.insert(curr); // mark visited
  path.push_back(curr);
  for (auto neighbour : graph[curr]) {
    if (!visited.count(neighbour)) {
      dfs(neighbour, end, path);
    }
  }
  path.pop_back();
  visited.erase(curr);
  return;
}
void AllPath(int src, int dest) {
  vector<int> v;
  dfs(src, dest, v);
}
int main() {
  cin >> v;
  graph.resize(v, list<int>());
  int e;
  cin >> e;
  while (e--) {
    int s, d;
    cin >> s >> d;
    add_edge(s, d);
  }
  int x, y;
  cin >> x >> y;
  AllPath(x, y);
  for (auto path : result) {
    for (auto el : path) {
      cout << el << "  ";
    }
    cout << endl;
  }
  return 0;
}