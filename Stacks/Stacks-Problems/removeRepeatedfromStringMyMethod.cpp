// My method is to solve this Question

#include <iostream>
#include <stack>
#include <string>
using namespace std;
void printStack(stack<char> &st)
{
    stack<char> temp;
    while (st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    while (temp.size())
    {
        cout << temp.top();
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}
void Remove(string s)
{
    int n = s.length();
    stack<char> st;
    st.push(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (st.top() == s[i])
        {
        }
        else
        {
            st.push(s[i]);
        }
    }
    printStack(st);
}
int main()
{
    string s;
    cout << " Enter a String : ";
    cin >> s;
    Remove(s);

    return 0;
}