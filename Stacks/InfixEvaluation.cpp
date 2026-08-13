#include <iostream>
#include <stack>
using namespace std;
int solve(int val1, int val2, char op)
{
    if (op == '+')
        return val1 + val2;
    else if (op == '-')
        return val1 - val2;
    else if (op == '*')
        return val1 * val2;
    else
        return val1 / val2;
}
int prio(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
}

int main()
{
    // int x=2+8*3/4-5;
    // cout<<x;
    string s = "2+6*4/8-3"; // I want the value is printed   "Infix-Expression"
    //    we need two Stacks one for values and another for operators
    stack<int> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        // Check if s[i] is a digit (0-9) by checking their ASCII values
        if (s[i] >= 48 && s[i] <= 57)
        { // digit
            val.push(s[i] - 48);  // in this way we are pushing the integer values by subtracting the 0 ASCII values 
        }
        else
        { // s[i] is operators (+,-,/,*)
            if (op.size() == 0 || prio(s[i]) > prio(op.top()))
                op.push(s[i]);
            else
            { // prio(s[i])<=prio(op.top())
                while (op.size() && prio(s[i]) <= prio(op.top()))
                {
                    // I have to do val1 op val2 kaam krna h
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    // The operator stack can have values
    // so make it empty
    while (op.size())
    {
        // Work
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }
cout<<val.top()<<endl;

    return 0;
}