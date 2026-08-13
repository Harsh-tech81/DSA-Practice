#include <bits/stdc++.h>
using namespace std;
// It is not submitted but passes all the test cases 
#define ll long long int
int find(vector<int> &par, int x) {
  return par[x] = (par[x] == x) ? x : find(par, par[x]);
}
void Union(vector<int> &par, vector<int> &rank, vector<int> &sz, int a, int b) {
  a = find(par, a);
  b = find(par, b);
  if (a == b)
    return;
  if (rank[a] > rank[b]) {
    rank[a]++;
    sz[a] += sz[b];
    par[b] = a;
  } else {
    rank[b]++;
    sz[b] += sz[a];
    par[a] = b;
  }
}
struct Edge {
  int src;
  int des;
  int wt;
};
bool cmp(Edge e1, Edge e2) { return e1.wt < e2.wt; }

ll kruskals(vector<Edge> &ipt, int n, int e) {
  sort(ipt.begin(), ipt.end(), cmp);
  vector<int> par(n + 1);
  vector<int> rank(n + 1, 0);
  vector<int> sz(n + 1, 1);
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  int edgeCount = 0; // n-1
  int i = 0;
  ll ans = 0;
  while (edgeCount < n - 1 && i < ipt.size()) {
    Edge curr = ipt[i];
    int srcPar = find(par, curr.src);
    int desPar = find(par, curr.des);
    if (srcPar != desPar) {
      Union(par, rank, sz, srcPar, desPar);
      ans += curr.wt;
      edgeCount++;
    }
    i++;
  }
  return ans;
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, e;
    cin >> n >> e;
    vector<Edge> v(e);
    for (int i = 0; i < e; i++) {
      cin >> v[i].src >> v[i].des >> v[i].wt;
    }
    vector<int> par(n + 1);
    vector<int> rank(n + 1, 0);
    vector<int> sz(n + 1, 1);
    for (int i = 0; i <= n; i++) {
      par[i] = i;
    }
    for (int i = 0; i < e; i++) {
      int x = v[i].src;
      int y = v[i].des;
      Union(par, rank, sz, x, y);
    }
    bool f = false;
    for (int el : sz) {  // here we have checked the no. of components there is another way to check it using parent array itself  if(find(par,i)==i)
        // comp++;  if(comp>1) return -1;
      if (el == n) {
        f = true;
        break;
      }
    }
    if (!f)
      cout << -1 << endl;
    else
      cout << kruskals(v, n, e) << endl;
  }
  return 0;
}
