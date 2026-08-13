#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int odd = 0, even = 0;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            if (x % 2 == 0)
                even++;
            else
                odd++;
        }
        if (odd % 2 == 0 && even)
            cout << "YES" << endl;
        else if (odd == 2 && even == 0)
            cout << "YES" << endl;
        else if (even && odd % 2 != 0)
            cout << "NO" << endl;
        else if (even == 2 && odd == 0)
            cout << "YES" << endl;
        else if (even == 0 && odd >= 4)
        {
            if (odd % 2 == 0)
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
        }
        else if (even == 0 && odd < 4)
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}