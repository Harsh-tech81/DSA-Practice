#include <bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v;
void add_edge(int src, int dest, bool bi_dir = true) {
  graph[src].push_back(dest);
  if (bi_dir) {
    graph[dest].push_back(src);
  }
}
void display() {
  for (int i = 0; i < graph.size(); i++) {
    cout << i << " -> ";
    for (auto el : graph[i]) {
      cout << el << " , ";
    }
    cout << endl;
  }
}
bool dfs(int src, int parent, unordered_set<int> &vis) {
  for (auto neighbour : graph[src]) {
    if (vis.count(neighbour) && neighbour != parent)
      return true; // cycle detected
    if (!vis.count(neighbour)) {
      vis.insert(neighbour);
      bool res = dfs(neighbour, src, vis);
      if (res)
        return true;
    }
  }
  return false;
}

bool has_cycle() {
  unordered_set<int> vis;
  bool res = false;
  for (int i = 0; i < v; i++) {
    if (!vis.count(i)) {
      vis.insert(i);
      res = dfs(i, -1, vis);
      if (res)
        return true;
    }
  }
  return false;
}

int main() {
  cin >> v;
  graph.resize(v, list<int>());
  int e;
  cin >> e;
  while (e--) {
    int s, d;
    cin >> s >> d;
    add_edge(s, d, false);
  }
//   display();
  bool res = has_cycle();
  if (res)
    cout << "Cycle detected in graph" << endl;
else cout<<"Cycle is not detected in graph" << endl;
  return 0;
}