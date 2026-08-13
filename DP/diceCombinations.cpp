#include <bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;
ll f(int n, vector<ll> &dp)
{
   if (n == 0)  // you can put the condition n==1 return 1
      return 1;
   if (dp[n] != -1)
      return dp[n];
   ll sum = 0;
   for (int i = 1; i <= 6; i++)
   {
      if (n - i < 0)
         break;
      sum = (sum % mod + f(n - i, dp) % mod) % mod;
   }
   return dp[n] = sum % mod;
}


// ll fpu(int n, vector<ll> &dp)
// {
//    dp[0] = 1;
//    for (int k = 1; k <= n; k++)
//    {
//       ll sum = 0;
      
//       for (int i = 1; i <= 6; i++)
//       {
      
//          if (k - i < 0)
//             break;
//          sum = (sum % mod + dp[k - i] % mod) % mod;
 
//       dp[k] = sum % mod;
//    }
//    }
//    return dp[n];
// }

int main()
{
   int n;
   cin >> n;
   vector<ll> dp(pow(10, 6) + 1,-1);
   cout << f(n, dp) << endl;
   // cout << fpu(n, dp) << endl;

   return 0;
}
