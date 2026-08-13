#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long ans = i * i;
        cout << (ans * (ans - 1)) / 2 - (4 * (i - 1) * (i - 2)) << endl;
    }
    return 0;
}