#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, ans = 0;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    sort(v.begin(), v.end());
    int i = 0, j = n - 1;
    while (i <= j)
    {
        if (v[i] + v[j] > x)
        {
            ans++;
            j--;
        }
        else
        {
            i++;
            j--;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}