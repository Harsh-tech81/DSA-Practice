#include <bits/stdc++.h>
using namespace std;
#define pp pair<int, int>
// 01 BFS (similar to Dijkstra's Algo but without using min-heap we used
// Dequeue)

// vector<list<pp>> graph;
// void add_edge(int src, int dest, int wgt, bool bi_dir = true) {
//   graph[src].push_back({dest, wgt});
//   if (bi_dir) {
//     graph[dest].push_back({src, wgt});
//   }
// }

// code story with MIK
// function to find the shortest distance of all the vertices from the src
// vertes S.
vector<int> dijkstra(int V, vector<list<pp>> graph, int S) {
  priority_queue<pp, vector<pp>, greater<pp>> pq;
  vector<int> res(V, INT_MAX);
  res[S] = 0;
  pq.push({0, S});
  // NOTE - you can add a visited vector to avoid revisiting a node again and
  // again.
  while (!pq.empty()) {
    int d = pq.top().first;
    int node = pq.top().second;
    pq.pop();
    for (auto &vec : graph[node]) {
      int adjNode = vec[0];
      int dist = vec[1];
      if (d + dist < res[adjNode]) {
        res[adjNode] = d + dist;
        pq.push({d + dist, adjNode});
      }
    }
  }
  return res;
}

vector<int> 01BFS(int V, vector<list<pp>> graph, int S) {
 deque<pp>dq;  // deque m bhi do cheez store krn pregi (cost,Node)
  vector<int> res(V, INT_MAX);
  res[S] = 0;
  dq.push_front({0, S});
  // NOTE - you can add a visited vector to avoid revisiting a node again and
  // again.
  while (!dq.empty()) {
   auto [d,node]=dq.front();
   dq.pop_front();
    for (auto &vec : graph[node]) {
      int adjNode = vec[0];
      int dist = vec[1];
      if (d + dist < res[adjNode]) {
        res[adjNode] = d + dist;
       if(dist==0) dq.push_front({dist+d,adjNode});  // so that we can get the deque elements in sorted fashion
       else  dq.push_back({dist+d,adjNode});
      }
    }
  }
  return res;
}


int main() {

  //   int n, m;
  //   cin >> n >> m;
  //   graph.resize(n, list<pp>());
  //   while (m--) {
  //     int s, d, w;
  //     cin >> s >> d >> w;
  //     add_edge(s, d, w);
  //   }
  //   int src;
  //   cin >> src;
  //   int des;
  //   cin >> des;
  //   cout << mp[des] << endl;
  //   for (auto x : mp) {
  //     cout << x.first << " " << x.second << endl;
  //   }

  return 0;
}