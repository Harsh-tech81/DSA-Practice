#include <bits/stdc++.h>
using namespace std;
// Union By Rank with Path compression
int find(vector<int> &par, // Time complexity is O(log*N) what this log*N is How
                           // many times we apply logN so that its value is less
                           // than or equal to 1
         int x) { // this method returns which group/cluster x belongs to
  return par[x] = (par[x] == x) ? x : find(par, par[x]);
}
void Union(vector<int> &par, vector<int> &rank, int a, int b) {
  a = find(par, a);
  b = find(par, b);
  if(a==b) return;
  if (rank[a] > rank[b]) {
    rank[a]++;
    par[b] = a;
  } else {
    rank[b]++;
    par[a] = b;
  }
}
int main() {
  int n, m;
  // n-->No. of Elements and m-->No. of Queries
  cin >> n >> m;
  vector<int> par(n + 1);
  vector<int> rank(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    par[i] = i;
  }
  while (m--) {
    string str;
    cin >> str;
    if (str == "union") {
      int x, y;
      cin >> x >> y;
      Union(par, rank, x, y);
    } else {
      int x;
      cin >> x;
      cout << find(par, x) << endl;
    }
  }

  return 0;
}