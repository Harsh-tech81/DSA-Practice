#include <bits/stdc++.h>
using namespace std;

// int f(int n, vector<int> &arr)  // top-down method
// {
//     if (n == 0)
//         return 0;
//     int mn = INT_MAX;
//     if (dp[n] != -2)
//         return dp[n];
//     for (int i = 0; i < arr.size(); i++)
//     {
//         if (n - arr[i] < 0)
//             continue;
//         mn = min(f(n - arr[i], arr), mn);
//     }
//     if (mn == INT_MAX)
//         return dp[n] = INT_MAX;
//     return dp[n] = 1 + mn;
// }

int main()
{
    // vector<int> dp(pow(10, 4) + 10);
    // vector<int> coins = {1};
    // int money = 0;
    int n, money;
    vector<int> dp(pow(10, 6) + 10);
    cin >> n >> money;
    vector<int> coins;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        coins.push_back(num);
    }
    // int ans = f(money, coins);
    // if (ans == INT_MAX)
    //     cout << -1 << endl;
    // else
    //     cout << ans << endl;

    // Bottom Up Solution
    dp[0] = 0;
    for (int i = 1; i <= money; i++)
    {
        int mn = INT_MAX;
        for (int j = 0; j < coins.size(); j++)
        {
            if (i - coins[j] < 0)
                continue;
            mn = min(dp[i - coins[j]], mn);
        }
        if (mn == INT_MAX)
            dp[i] = INT_MAX;
        else
            dp[i] = 1 + mn;
    }
    int ans = dp[money];
    if (ans == INT_MAX)
        cout << -1 << endl;
    else
        cout << ans << endl;

    return 0;
}