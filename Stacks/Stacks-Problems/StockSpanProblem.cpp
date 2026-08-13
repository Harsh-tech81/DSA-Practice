// Stock Span Problem
// copy paste of the Previous Greater Element

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> vec = {100, 80, 60, 70, 60, 75, 85};
    int n = vec.size();
    vector<int> ans(n);
    ans[0] = 1;
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; i++)
    {
        // Pop all the elements smaller than or equal to vec[i]
        while (st.size() && vec[st.top()] <= vec[i])
            st.pop(); // Pop
        //    Mark the ans in ans array
        if (st.size() != 0)
            ans[i] = st.top(); // Ans-Mark
        else
            ans[i] = -1;

        ans[i] = i - ans[i];
        st.push(i); // Push the vec[i]
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "  ";
    }

    return 0;
}