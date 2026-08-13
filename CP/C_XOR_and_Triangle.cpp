#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;
        bool f = false;
        for (long long i = n - 1; i >= 1; i--)
        {
            long long x = i ^ n;
            if (((i + x )> n) && ((i + n) > x) && ((n + x) > i))
            {
                cout << i << endl;
                f = true;
                break;
            }
        }
        if (!f)
            cout << -1 << endl;
    }

    return 0;
}