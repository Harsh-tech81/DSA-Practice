#include <bits/stdc++.h>
using namespace std;

int hcf(int a, int b) { // T.C. --> O(min(a,b))
  for (int i = min(a, b); i > 1; i--) {
    if (a % i == 0 && b % i == 0)
      return i;
  }
  return 1;
}

int recgcd(int a, int b) {
  if (a == 0) {
    return b;
  } else
    return recgcd(b % a, a);
}

int main() {
  int a = 24;
  int b = 60;
  // cout<<hcf(27,45)<<endl;
  cout << recgcd(60, 24) << endl;

  return 0;
}