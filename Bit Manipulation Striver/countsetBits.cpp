#include <bits/stdc++.h>
using namespace std;
int countSetBits(int n) {
  int cnt = 0;
  while (n > 0) {
    cnt += n & 1;
    n >>= 1;
  }
  return cnt;
}
int main() {
  int n;
  cin >> n;
  cout << countSetBits(n) << endl;
  return 0;
}