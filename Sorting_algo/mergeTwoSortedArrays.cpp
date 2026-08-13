#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v1, vector<int> &v2, vector<int> &ans) {
  int i = 0, j = 0, k = 0;
  int n = v1.size();
  int m = v2.size();
  while (i < n && j < m) {
    if (v1[i] <= v2[j]) {
      ans[k] = v1[i];
      i++;
    } else {
      ans[k] = v2[j];
      j++;
    }
    k++;
  }
  if (i == n) {
    for (int i = j; i < m; i++) {
      ans[k++] = v2[i];
    }
  }
  if (j == m) {
    for (int j = i; j < n; j++) {
      ans[k++] = v1[j];
    }
  }
}

int main() {
  int n, m;
  cout << "Enter the size of first Array " << endl;
  cin >> n;
  vector<int> v1(n);
  for (int i = 0; i < n; i++)
    cin >> v1[i];
  cout << "Enter the size of second Array " << endl;
  cin >> m;
  vector<int> v2(m);
  for (int i = 0; i < m; i++)
    cin >> v2[i];
  vector<int> ans(n + m);
  merge(v1, v2, ans);
  for (int el : ans)
    cout << el << " ";
  cout << endl;

  return 0;
}