#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long sum = (n * (n + 1)) / 2;
    if (sum % 2 != 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    vector<int> v;

    if (n % 2 == 0)
        for (int i = 1; i <= n; i++)
            v.push_back(i);
    else
    {
        v.push_back(0);
        for (int i = 1; i <= n; i++)
            v.push_back(i);
    }
    int i = v.size() - 1;
    int j = v.size() - 2;
    bool flag = true;
    while (i > 0 && j >= 0)
    {
        if (!flag)
        {
            swap(v[i], v[j]);
            flag = true;
        }
        else
        {
            flag = false;
        }
        i -= 2;
        j -= 2;
    }
    if (n % 2 == 0)
    {
        cout << "YES" << endl;
        cout << n / 2 << endl;
        for (int i = 0; i < v.size(); i += 2)
        {
            if (v[i])
                cout << v[i] << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for (int i = 1; i < v.size(); i += 2)
        {
            if (v[i])
                cout << v[i] << " ";
        }
    }
    else
    {
        cout << "YES" << endl;
        cout << n / 2 + 1 << endl;
        for (int i = 0; i < v.size(); i += 2)
        {
            if (v[i])
                cout << v[i] << " ";
        }
        cout << endl;
        cout << n / 2 << endl;
        for (int i = 1; i < v.size(); i += 2)
        {
            if (v[i])
                cout << v[i] << " ";
        }
    }

    return 0;
}