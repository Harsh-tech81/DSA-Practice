// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int k, l, m;
//   // m--> Number of Games first compute for the total then compute the index
//   // just give me the value of the dp at the index of m1,m2.... of m(No. of
//   // Games)
//   cin >> k >> l >> m;
//   vector<bool> dp(pow(10, 6) + 1, 0);
//   dp[1] = 1;
//   dp[k] = 1;
//   dp[l] = 1;
//   for (int i = 2; i <= 1000000; i++) {
//     if (i == k || i == l) // base case already computed
//       continue;
//     dp[i] = !(dp[i - 1] && ((i - k >= 1) ? dp[i - k] : 1) &&
//               ((i - k >= 1) ? dp[i - l] : 1));
//   }
//   for (int i = 1; i <= m; i++) {
//     int n;
//     cin >> n; // where n is the no. of coins in the m game
//     if (dp[n] == 1) {
//       cout << "A"; // n-->winning state
//     } else {
//       cout << "B"; // n-->loosing state
//     }
//   };

//   return 0;
// }


#include <iostream>
#include<vector>
#include<cmath>
using namespace std;
int main() {
int k, l, m;
  cin >> k >> l >> m;
  vector<bool> dp(pow(10, 6) + 1, 0);
  dp[1] = 1;
  dp[k] = 1;
  dp[l] = 1;
  for (int i = 2; i <= 1000000; i++) {
    if (i == k || i == l)
      continue;
    dp[i] = !(dp[i - 1] && ((i - k >= 1) ? dp[i - k] : 1) &&
              ((i - l >= 1) ? dp[i - l] : 1));
  }

  for (int i = 1; i <= m; i++) {
    int n;
    cin >> n;        
    if (dp[n] == 1) { 
      cout << "A"; 
    } else {
      cout << "B";  
    }
  }
	return 0;
}