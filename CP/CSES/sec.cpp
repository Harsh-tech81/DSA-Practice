#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, k, count = 0;
    cin >> n >> m >> k;
    vector<int> v1(n), v2(m);
    for (int i = 0; i < n; i++)
        cin >> v1[i];
    for (int i = 0; i < m; i++)
        cin >> v2[i];
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (v2[j] >= v1[i] - k && v2[j] <= v1[i] + k)
        {
            count++;
            i++;
            j++;
        }
        else if (v2[j] < v1[i] - k)
        {
            j++;
        }
        else if (v2[j] > v1[i] + k)
        {
            i++;
        }
    }
    cout << count << endl;
    return 0;
}