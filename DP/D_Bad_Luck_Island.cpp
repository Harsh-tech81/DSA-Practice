#include <bits/stdc++.h>
using namespace std;
#define ld long double
#define ll long int
ld dp[105][105][105];
// Nice codeforces D of Div-2 problem rated 1900 DP with probabilities type of Q 
ld Fr(int r, int s, int p) {
  if (r == 0 || s == 0)
    return 0.0;
  if (p == 0)
    return 1.0;
  if (dp[r][s][p] > -0.9)
    return dp[r][s][p]; // always keep this in mind for the probability Q
  ld total = r * s + s * p + r * p;
  ld res = 0.0;
  res += Fr(r, s - 1, p) * ((r * s) / total);
  res += Fr(r - 1, s, p) * ((r * p) / total);
  res += Fr(r, s, p - 1) * ((p * s) / total);
  return dp[r][s][p] = res;
}
ld Fp(int r, int s, int p) {
  if (r == 0 || p == 0)
    return 0.0;
  if (s == 0)
    return 1.0;
  if (dp[r][s][p] > -0.9)
    return dp[r][s][p];
  ld total = r * s + s * p + r * p;
  ld res = 0.0;
  res += Fp(r, s - 1, p) * ((r * s) / total);
  res += Fp(r - 1, s, p) * ((r * p) / total);
  res += Fp(r, s, p - 1) * ((p * s) / total);
  return dp[r][s][p] = res;
}
ld Fs(int r, int s, int p) {
  if (p == 0 || s == 0)
    return 0.0;
  if (r == 0)
    return 1.0;
  if (dp[r][s][p] > -0.9)
    return dp[r][s][p]; 
  ld total = r * s + s * p + r * p;
  ld res = 0.0;
  res += Fs(r, s - 1, p) * ((r * s) / total);
  res += Fs(r - 1, s, p) * ((r * p) / total);
  res += Fs(r, s, p - 1) * ((p * s) / total);
  return dp[r][s][p] = res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  ll r, s, p;
  cin >> r >> s >> p;
  memset(dp, -1.0, sizeof dp);
  ld Fr_ans1 = Fr(r, s, p);
  memset(dp, -1.0, sizeof dp);
  ld Fs_ans2 = Fs(r, s, p);
  memset(dp, -1.0, sizeof dp);
  ld Fp_ans3 = Fp(r, s, p);
  cout << fixed << setprecision(12) << Fr_ans1 << " ";
  cout << fixed << setprecision(12) << Fs_ans2 << " ";
  cout << fixed << setprecision(12) << Fp_ans3 << endl;

  return 0;
}