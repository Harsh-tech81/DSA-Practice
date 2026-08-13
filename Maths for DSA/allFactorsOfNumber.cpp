#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n) {
  if (n < 2)
    return false;
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0)
      return false;
  }
  return true;
}
vector<int> v;
void printDivisors(int n) {  // print all the divisors as well as the print all the prime divisors of the number 
  for (int i = 1; i * i <= n; i++) { // O(sqrt(n))
    if (n % i == 0) {
      if (isPrime(i))
        v.push_back(i);
      if ((n / i) != i)
        if (isPrime(n / i))
          v.push_back(n / i);
    }
  }
  sort(v.begin(), v.end());
}
int main() {
  int n;
  cin >> n;
  printDivisors(n);
  for (int el : v) {
    cout << el << " ";
  }
  cout << endl;

  return 0;
}