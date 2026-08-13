#include <bits/stdc++.h>
using namespace std;

// int hcf(int a, int b) { // T.C. --> O(min(a,b))
//   for (int i = min(a, b); i > 1; i--) {
//     if (a % i == 0 && b % i == 0)
//       return i;
//   }
//   return 1;
// }

// Now GCD code by Euclid's Algorithm
int gcd(int a, int b) {
  while (a > 0 && b > 0) {
    if (a > b)
      a = a % b;
    else
      b = b % a;
  }
  if (a == 0)
    return b;
  return a;
}
// int recgcd(int a, int b) { // by default we assume a>=b
//   if (b == 0) {
//     return a;
//   }
//   return recgcd(b, a % b);
// }
// // for finding the LCM of two numbers we use the mathematical formula
// int lcm(int a, int b) {
//   int gcd = recgcd(a, b);
//   return (a * b) / gcd;
// }
int main() {
  int a = 24;
  int b = 60;
  cout<<gcd(0,10)<<endl;
  // cout << lcm(28, 20) << endl;

  return 0;
}