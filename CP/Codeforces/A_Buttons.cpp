#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c;
        cin >> a >> b >> c;   
        int anna_total = a + ceil(c/2.0);  // Anna goes first, gets ceiling
        int katie_total = b + c / 2;
        
        if (anna_total > katie_total) {
            cout << "First" << endl;
        } else {
            cout << "Second" << endl;
        }
    }
    return 0;
}