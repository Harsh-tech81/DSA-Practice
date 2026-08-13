#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        if (n == m)
        {
            int cnt = 0;
            int pro = 1;
            bool f1 = false;
            bool f2 = true;
            do
            {
                if (f1)
                {
                    if (n - pro >= 0)
                        n -= pro;
                        else break;
                    f1 = false;
                    f2 = true;
                }
                else if (f2)
                {
                    if (m - pro >= 0)
                        m -= pro;
                        else break;
                    f2 = false;
                    f1 = true;
                }
                cnt++;
                pro *= 2;
            }while(pro <= n || pro <= m);
            cout << cnt << endl;
        }
        else
        {
            int x=n;
            int y=m;
            int cnt1 = 0;
            int pro1 = 1;
            bool f11 = false;
            bool f21 = true;
           do
            {
                if (f11)
                {
                    if (n - pro1 >= 0)
                        n -= pro1;
                         else break;
                    f11 = false;
                    f21 = true;
                }
                else if (f21)
                {
                    if (m - pro1 >= 0)
                        m -= pro1;
                         else break;
                    f21 = false;
                    f11 = true;
                }
                cnt1++;
                pro1 *= 2;
            } while (pro1 <= n || pro1 <= m);
            int cnt = 0;
            int pro = 1;
            bool f1 = true;
            bool f2 = false;
            do
            {
                if (f1)
                {
                    if (x - pro >= 0)
                        x -= pro;
                         else break;
                    f1 = false;
                    f2 = true;
                }
                else if (f2)
                {
                    if (y - pro >= 0)
                        y -= pro;
                         else break;
                    f2 = false;
                    f1 = true;
                }
                cnt++;
                pro *= 2;
            }while (pro <= x || pro <= y);
            cout << max(cnt, cnt1) << endl;
        }
    }
    return 0;
}