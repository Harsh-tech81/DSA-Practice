#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> freq;  
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        freq[x]++;  
    }
    for (int i = 0; i < m; i++)
    {
        int query;
        cin >> query;
        auto it = freq.upper_bound(query);
        if (it != freq.begin())
        {
            --it;  
            cout << it->first << "\n";
            freq[it->first]--;
            if (freq[it->first] == 0)
            {
                freq.erase(it);
            }
        }
        else
        {
            cout << -1 << "\n";
        }
    }
    
    return 0;
}