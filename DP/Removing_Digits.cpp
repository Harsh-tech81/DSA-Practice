#include <bits/stdc++.h>
using namespace std;
vector<int> dp(pow(10, 6) + 5);
vector<int> findDigit(int n)
{
    vector<int> ans;
    while (n)
    {
        int ld = n % 10;
        n /= 10;
        if (ld > 0)
            ans.push_back(ld);
    }
    return ans;
}

int f(int n)
{
    int mn = INT_MAX;
    if (n == 0)
        return 0;
    if (n <= 9)
        return 1;
    if (dp[n] != -1)
        return dp[n];
    vector<int> d = findDigit(n);
    for (int i = 0; i < d.size(); i++)
    {
        mn = min(f(n - d[i]), mn);
    }
    return dp[n] = 1 + mn;
}

int main()
{

    int n;
    cin >> n;
    // cout << f(n);

    dp[0] = 0;
    for (int i = 1; i <= 9; i++)
    {
        dp[i] = 1;
    }
    for (int i = 10; i <= n; i++)
    {
        vector<int> d = findDigit(i);
        int mn = INT_MAX;
        for (int j = 0; j < d.size(); j++)
        {
            mn = min(dp[i - d[j]], mn);
        }
        dp[i] = 1 + mn;
    }
    cout << dp[n] << endl;

    return 0;
}