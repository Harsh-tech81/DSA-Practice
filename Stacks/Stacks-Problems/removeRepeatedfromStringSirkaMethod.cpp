#include <iostream>
#include <stack>
#include <string>
#include <bits/stdc++.h> // this header file is so important for using any in-built function of the string as for example reverse of the string
using namespace std;
string removeDuplicates(string s)
{
    stack<char> st;
    int n = s.length();
    st.push(s[0]);
    for (int i = 1; i < n; i++)
    {
        if (s[i] != st.top())
            st.push(s[i]);
    }
    s = "";
    while (st.size())
    {
        s += st.top();
        st.pop();
    }
    reverse(s.begin(), s.end()); // it is only used when we have included the bits stdc++.h wala header file bcz this header file is too much important for using
    return s;
}

int main()
{
    string s;
    cout << " Enter a String : ";
    cin >> s;
    cout << removeDuplicates(s);

    return 0;
}