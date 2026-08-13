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
        string s(n,' ');
        cin >> s;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < n - 3; i++)
        {
            if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '5')
                cnt1++;
            else if (s[i] == '2' && s[i + 1] == '0' && s[i + 2] == '2' && s[i + 3] == '6')
                cnt2++;
        }
        if (cnt2)
            cout << 0 << endl;
        else if (cnt1 > 0)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}