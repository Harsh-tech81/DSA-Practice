#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int l, a, b;
        cin >> l >> a >> b;
        unordered_set<int> st;
        st.insert(a);
        int mx = a;
        while (1)
        {
            int cal = (a + b) % l;
            if (st.find(cal) == st.end())
            {
                st.insert(cal);
                mx = max(mx, cal);
                a = cal;
            }
            else
                break;
        }
        cout << mx << endl;
    }

    return 0;
}