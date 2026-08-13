#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n;
    cin >> n;
    long long mx = -1; // use the concept of the previous greater element always try to use long long in CSES type of the Question
    long long ans = 0;
    for (long long i = 1; i <= n; i++)
    {
        long long x;
        cin >> x;
        mx = max(mx, x);
        ans += (mx - x);
    }
    cout << ans << endl;
    return 0;
}