#include <bits/stdc++.h>
#define ll long long int
#define pp pair<int, int>
using namespace std;
// Dijkstra's Algorithm
vector<list<pp>> graph;
void add_edge(int src, int dest, int wgt, bool bi_dir = true) {
  graph[src].push_back({dest, wgt});
  if (bi_dir) {
    graph[dest].push_back({src, wgt});
  }
}


unordered_map<int, int> dijkstra(int src, int n) { // T.C.  --> O((V+E)logV)
  unordered_set<int> vis;
  priority_queue<pp, vector<pp>, greater<pp>> pq; // minHeap ({dist,node})
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) { // O(V)
    mp[i] = INT_MAX;
  }
  vector<int> via(n);
  pq.push({0, src});
  mp[src] = 0;
  while (!pq.empty()) { // O((V+E)*logV)
    pp curr = pq.top();
    pq.pop();
    if (!vis.count(curr.second)) {  // mark node visited
      vis.insert(curr.second);
      for (auto neighbour : graph[curr.second]) {
        if (!vis.count(neighbour.first) &&
            mp[neighbour.first] >
                mp[curr.second] + neighbour.second) { // Relaxation Algorithm
          pq.push({mp[curr.second] + neighbour.second, neighbour.first});
          via[neighbour.first] = curr.second;
          mp[neighbour.first] = mp[curr.second] + neighbour.second;
        }
      }
    }
  }
  return mp;
}


int main() {

  int n, m;
  cin >> n >> m;
  graph.resize(n, list<pp>());
  while (m--) {
    int s, d, w;
    cin >> s >> d >> w;
    add_edge(s, d, w);
  }
  int src;
  cin >> src;
  unordered_map<int, int> mp = dijkstra(src, n);
  int des;
  cin >> des;
  //   cout << mp[des] << endl;
  for (auto x : mp) {
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}