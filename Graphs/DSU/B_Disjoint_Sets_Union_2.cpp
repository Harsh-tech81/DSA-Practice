#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &par, int x) {
  return par[x] = (par[x] == x) ? x : find(par, par[x]);
}
void Union(vector<int> &par, vector<int> &sz, vector<int> &minimal,
           vector<int> &maximal, vector<int> &rank, int a, int b) {
  a = find(par, a);
  b = find(par, b);
  if (a == b)
    return; // both a and b are same set
  if (rank[a] > rank[b]) {
    rank[a]++;
    par[b] = a;
    sz[a] += sz[b];
    maximal[a] = max(maximal[a], maximal[b]);
    minimal[a] = min(minimal[a], minimal[b]);
  } else {
    rank[b]++;
    par[a] = b;
    sz[b] += sz[a];
    maximal[b] = max(maximal[a], maximal[b]);
    minimal[b] = min(minimal[a], minimal[b]);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> par(n + 1);
  vector<int> rank(n + 1, 0);
  vector<int> sz(n + 1, 1);
  vector<int> minimal(n + 1);
  vector<int> maximal(n + 1);
  for (int i = 0; i <= n; i++) {
    par[i] = minimal[i] = maximal[i] = i;
  }
  while (m--) {
    string str;
    cin >> str;
    if (str == "union") {
      int x, y;
      cin >> x >> y;
      Union(par, sz, minimal, maximal, rank, x, y);
    } else {
      int x;
      cin >> x;
      x = find(par, x);
      cout << minimal[x] << " " << maximal[x] << " " << sz[x] << endl;
    }
  }

  return 0;
}