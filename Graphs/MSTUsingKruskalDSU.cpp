#include <bits/stdc++.h>
using namespace std;
#define ll long long int
int find(vector<int> &par, int x) {
  return par[x] = (par[x] == x) ? x : find(par, par[x]);
}
void Union(vector<int> &par, vector<int> &rank, int a, int b) {
  a = find(par, a);
  b = find(par, b);
  if (a == b)
    return;
  if (rank[a] > rank[b]) {
    rank[a]++;
    par[b] = a;
  } else {
    rank[b]++;
    par[a] = b;
  }
}
struct Edge {
  int src;
  int des;
  int wt;
};
bool cmp(Edge e1, Edge e2) { // comparator for sorting in ascending order
                             // according to the weight
  return e1.wt < e2.wt;
}

ll kruskals(vector<Edge> &ipt, int n, int e) {
  sort(ipt.begin(), ipt.end(), cmp);
  vector<int> par(n + 1);
  vector<int> rank(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  int edgeCount = 0; // n-1
  int i = 0;
  ll ans = 0;
  while (edgeCount < n - 1 && i < ipt.size()) {
    Edge curr = ipt[i]; // because input is sorted so we will get min wt edge.
    int srcPar = find(par, curr.src);
    int desPar = find(par, curr.des);
    if (srcPar != desPar) {
      // include this edge as it doesn't forms cycle
      Union(par, rank, srcPar, desPar);
      ans += curr.wt;
      edgeCount++;
    }
    i++; // It doesn't matter we have picked the last edge or not ,we still need
         // to go to next Edge.
  }
  return ans;
}

int main() {
  int n, e;
  cin >> n >> e;
  vector<Edge> v(e);
  for (int i = 0; i < e; i++) {
    cin >> v[i].src >> v[i].des >> v[i].wt;
  }
  cout << kruskals(v, n, e) << endl;

  return 0;
}