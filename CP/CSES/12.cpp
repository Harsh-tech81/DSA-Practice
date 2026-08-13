#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long y, x;
        cin >> x >> y;
        long long ans;
        if (x <= y)
        {
            if (y % 2 != 0)
                ans = y * y - x + 1;
            else
                ans = (y - 1) * (y - 1) + x;
        }
        else
        {
            if (x % 2 != 0)
                ans = (x - 1) * (x - 1) + y;
            else
                ans = x * x - y + 1;
        }

        cout << ans << endl;
    }
    return 0;
}