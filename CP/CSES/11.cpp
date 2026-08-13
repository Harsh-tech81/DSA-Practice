#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long n, m;
    cin >> n >> m;
    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
        cin >> v[i];
    for (long long i = 1; i < n; i++)
    {
        v[i] = v[i] + v[i - 1];
    }
    while (m--)
    {
        long long x, y;
        cin >> x >> y;
        if (x <= 1)
        {
            cout << v[y - 1] << endl;
        }
        else
        {
            cout << v[y - 1] - v[x - 2] << endl;
        }
    }

    return 0;
}