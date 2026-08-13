// numeric result, base <= 10
long long convertNumeric(long long n, int base) {
  if (n == 0)
    return 0;
  long long ans = 0;
  long long place = 1;
  while (n > 0) {
    int ld = n % base; // remainder
    ans += ld * place; // add digit at correct decimal place
    place *= 10;
    n /= base;
  }
  return ans; // e.g. n=13, base=2 -> 1101
}