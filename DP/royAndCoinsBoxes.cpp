#include <bits/stdc++.h>
using namespace std;
int main() { // this code is accepted on hackerearth there arr two ways of
             // making the F array both ways are submitted successfully 
  int n, m;
  cin >> n >> m;
  // vector<int> L(n + 1, 0), R(n + 1, 0);

  // while (m--) {
  //   int x, y;
  //   cin >> x >> y;
  //   L[x]++;
  //   R[y]++;
  // }
  // vector<int> F(n + 1, 0);
  // F[1] = L[1];
  // for (int i = 2; i <= n; i++) {
  //   F[i] = L[i] - R[i - 1] + F[i - 1];
  // }

  // Now second way to make the F array and take prefix sum which is more efficient than previous one by making the two extra arrays L and R 
  vector<int> F(n + 8, 0);
  while (m--) {
    int x, y;
    cin >> x >> y;
    F[x]++;
    F[y + 1]--;
  }

  for(int i=1;i<n+8;i++){
    F[i]+=F[i-1];
  }

  vector<int> Suff(n + 1, 0);
  for (int i = 0; i <= n; i++) {
    int coins = F[i];
    Suff[coins]++;
  }

  for (int i = n - 1; i >= 0; i--) {
    Suff[i] += Suff[i + 1];
  }

  int t2;
  cin >> t2;
  while (t2--) {
    int x;
    cin >> x;
    cout << Suff[x] << endl;
  }

  return 0;
}
