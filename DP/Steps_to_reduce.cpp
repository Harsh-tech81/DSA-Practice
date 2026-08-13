#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
#define inf INT_MAX
using namespace std;

// simple recursion code 
// int f(int n)
// {
//     if (n == 1)
//         return 0;
//     if (n == 2 || n == 3)
//         return 1;
//     return 1 + min(f(n - 1), min((n % 2 == 0) ? f(n / 2) : inf, (n % 3 == 0) ? f(n / 3) : inf));
// }

// int fdp(int n,vector<int>&dp)  // top down DP
// {
//     if (n == 1)
//         return 0;
//     if (n == 2 || n == 3)
//         return 1;
//         if(dp[n]!=-1) return dp[n];
//     return dp[n]=1 + min(f(n - 1), min((n % 2 == 0) ? fdp(n / 2,dp) : inf, (n % 3 == 0) ? fdp(n / 3,dp) : inf));
// }


int main()
{
    int n;
    cin >> n;
    // vector<int>dp(1000,-1);
    // cout << fdp(n,dp) << endl;

    // Bottom-Up Method Tabulation method (using Loops)
    vector<int>t(n+1);
    t[1]=0;
    t[2]=1;
    t[3]=1;
    for(int i=4;i<=n;i++){
        t[i]=1+min(t[i - 1], min((i % 2 == 0) ? t[i / 2] : inf, (i % 3 == 0) ? t[i / 3] : inf));
    }
    cout<<t[n]<<endl;

    return 0;
}