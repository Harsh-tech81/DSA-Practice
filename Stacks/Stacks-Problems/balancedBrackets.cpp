#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isBalanced(string s)
{
    stack<char> st; // Making a stack of the char datatype
    int n = s.length();
    if (n % 2 != 0)
        return false;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else
        {
            if (st.size() == 0)
                return false;
            else
                st.pop();
        }
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}

int main()
{
    string s;
    cout << " Enter a String containing ['(',')'] only : ";
    cin >> s;
    cout << isBalanced(s);

    return 0;
}