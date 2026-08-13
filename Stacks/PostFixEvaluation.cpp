#include <iostream>
#include <stack>
#include <cmath>
using namespace std;
int solve(int val1, int val2, char op)
{
    if (op == '+')
        return val1 + val2;
    else if (op == '-')
        return val1 - val2;
    else if (op == '*')
        return val1 * val2;
    else if (op == '^')
        return (int)round(pow(val1, val2));
    else
        return val1 / val2;
}
int main()
{
    string s = "562+*124/-";
    stack<int> val;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 48 && s[i] <= 57)
        {
            val.push(s[i] - 48);
        }
        else
        {
            int val2 = val.top();
            val.pop();
            int val1 = val.top();
            val.pop();
            int ans = solve(val1, val2, s[i]);
            val.push(ans);
        }
    }
cout << val.top() << endl;

    return 0;
}