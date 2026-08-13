#include <bits/stdc++.h>
using namespace std;
// to find the power x to the power n we assume x and n both are integers and
// both are non-negative numbers 
// T.C.  is O(log N base 2)
int powXtoN(int x, int n) {
  int ans = 1;
  while (n > 0) {
    if (n % 2 == 0) {
      x *= x;
      n /= 2;
    } else {
      ans *= x;
      n -= 1;
    }
  }
  return ans;
}

int main() {
  int x, n;
  cin >> x >> n;
  cout << powXtoN(x, n) << endl;

  return 0;
}