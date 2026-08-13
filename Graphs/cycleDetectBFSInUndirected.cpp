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
bool bfs(int src) {
  queue<int> qu;
  unordered_set<int> vis;
  vector<int> par(v, -1);
  qu.push(src);
  vis.insert(src);
  while (!qu.empty()) {
    int curr = qu.front();
    qu.pop();
    for (auto neighbour : graph[curr]) {
      if (vis.count(neighbour) && par[curr] != neighbour)
        return true;
      if (!vis.count(neighbour)) {
        qu.push(neighbour);
        vis.insert(neighbour);
        par[neighbour]=curr;
      }
    }
  }
  return false;
}

bool has_cycle() {
  unordered_set<int> vis;
  for (int i = 0; i < v; i++) {
    if (!vis.count(i)) {
      vis.insert(i);
     bool res = bfs(i);
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
  else
    cout << "Cycle is not detected in graph" << endl;

  return 0;
}