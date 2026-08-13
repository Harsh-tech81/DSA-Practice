#include <bits/stdc++.h>
using namespace std;
int BinaryToDecimal(int n) {
  int ans = 0;
  int x=1;
  while (n > 0) {
    int ld = n % 10;
   if(ld==1) ans += (ld * x);
    n /= 10;
    x*=2;
  }
  return ans;
}
int main() {
  int n;
  cin >> n;
  int ans = BinaryToDecimal(n);
  cout << ans << endl;

  return 0;
}