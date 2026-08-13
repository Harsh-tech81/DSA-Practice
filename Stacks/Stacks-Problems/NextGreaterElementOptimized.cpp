// Optimized Code name of this Meethod is ---
// Pop
// Answer Mark
// push
// Using Stack Data Structure (Pop Ans-Mark Push)  and Traverse in array in reverse order

#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main()
{
    vector<int> vec = {3, 1, 2, 5, 4, 6, 2, 3};
    int n = vec.size();
    vector<int> ans(n);
    ans[n - 1] = -1;
    stack<int> st;
    st.push(vec[n - 1]);
    for (int i = n - 2; i >= 0; i--)
    {
        // Pop all the elements smaller than arr[i]
        while (st.size() && st.top() <= vec[i])
            st.pop(); // Pop
        //    Mark the ans in ans array
        if (st.size() != 0)
            ans[i] = st.top(); // Ans-Mark
        else
            ans[i] = -1;

        st.push(vec[i]); // Push the vec[i]
    }

    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << "  ";
    }

    return 0;
}