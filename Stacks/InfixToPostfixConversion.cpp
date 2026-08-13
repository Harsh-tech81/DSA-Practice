#include <iostream>
#include <stack>
using namespace std;

int prio(char ch)
{
    if (ch == '+' || ch == '-')
        return 1;
    else
        return 2;
}
string solve(string val1, string val2, char op)
{
    // We have to store the prefix in the ans;
    // prefix --> op val1 val2
    string ans = val1 + val2 + op;
    return ans;
}
int main()
{
    // int x=2+8*3/4-5;
    // cout<<x;
    string s = "2+6*4/8-3"; // I want the value is printed   "Infix-Expression"
    //    we need two Stacks one for values and another for operators
    stack<string> val;
    stack<char> op;
    for (int i = 0; i < s.length(); i++)
    {
        // Check if s[i] is a digit (0-9) by checking their ASCII values
        if (s[i] >= 48 && s[i] <= 57)
        {                                   // digit
            val.push(to_string(s[i] - 48)); // in this way we are pushing the integer values by subtracting the 0 ASCII values
        }
        else
        { // s[i] is operators (+,-,/,*,(,))
            if (op.size() == 0)
                op.push(s[i]);
            else if (s[i] == '(')
                op.push(s[i]);
            else if (op.top() == '(')
                op.push(s[i]);
            else if (s[i] == ')')
            {
                // Kaam krna hoga
                while (op.top() != '(')
                {
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.pop(); // popping the opening bracket because after breaking the loop at the top of the op opening bracket is there and then remove it
            }
            else if (prio(s[i]) > prio(op.top()))
                op.push(s[i]);
            else
            { // prio(s[i])<=prio(op.top())
                while (op.size() && prio(s[i]) <= prio(op.top()))
                {
                    // I have to do val1 op val2 kaam krna h
                    char ch = op.top();
                    op.pop();
                    string val2 = val.top();
                    val.pop();
                    string val1 = val.top();
                    val.pop();
                    string ans = solve(val1, val2, ch);
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
        string val2 = val.top();
        val.pop();
        string val1 = val.top();
        val.pop();
        string ans = solve(val1, val2, ch);
        val.push(ans);
    }

    cout << val.top() << endl; // at last final answer is the val.top()

    return 0;
}