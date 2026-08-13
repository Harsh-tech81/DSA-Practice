#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;
// This  Prim's Algo  code is successfully submitted on the hackerrank
vector<list<pp>> graph;
void add_edge(int src, int dest, int wgt, bool bi_dir = true) {
  graph[src].push_back({dest, wgt});
  if (bi_dir) {
    graph[dest].push_back({src, wgt});
  }
}
ll prims(int src, int n) {
  unordered_set<int> vis;
  priority_queue<pp, vector<pp>, greater<pp>> pq; // minHeap ({wt,node})
  unordered_map<int, int> mp;
  for (int i = 0; i < n + 1; i++) {
    mp[i] = INT_MAX;
  }
  vector<int> par(n + 1);
  pq.push({0, src});
  mp[src] = -1;
  int total_count = 0; // 0 to n-1 edges maximum
  ll ans = 0;          // sum of wts store
  while (!pq.empty() && total_count < n + 1) {
    pp curr = pq.top();
    pq.pop();
    if (!vis.count(curr.second)) {
      vis.insert(curr.second);
      total_count++;
      ans += curr.first;
      for (auto neighbour : graph[curr.second]) {
        if (!vis.count(neighbour.first) &&
            mp[neighbour.first] > neighbour.second) {
          pq.push({neighbour.second, neighbour.first});
          par[neighbour.first] = curr.second;
          mp[neighbour.first] = neighbour.second;
        }
      }
    }
  }
  return ans;
}
int main() {

  int n, m;
  cin >> n >> m;
  graph.resize(n + 1, list<pp>());
  while (m--) {
    int s, d, w;
    cin >> s >> d >> w;
    add_edge(s, d, w);
  }
  int src;
  cin >> src;
  cout << prims(src, n) << endl;
  return 0;
}