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
void topoSortBFS() {
  // Kahn's Algo
  vector<int> indegrees(v, 0);
  for (int i = 0; i < v; i++) {
    for (auto neighbour : graph[i]) {
      // i-->neighbour
      indegrees[neighbour]++;
    }
  }
  queue<int> qu;
  unordered_set<int> vis;
  for (int i = 0; i < v; i++) {
    if (indegrees[i] == 0) {
      qu.push(i);
      vis.insert(i);
    }
  }
  while (!qu.empty()) {
    int node = qu.front();
    cout << node << " ";
    qu.pop();
    for (auto neighbour : graph[node]) {
      if (!vis.count(neighbour)) {
        indegrees[neighbour]--;
        if (indegrees[neighbour] == 0) {
          qu.push(neighbour);
          vis.insert(neighbour);
        }
      }
    }
  }
  cout<<endl;
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
  topoSortBFS();

//   display();

  return 0;
}