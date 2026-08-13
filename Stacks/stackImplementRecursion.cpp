#include <iostream>
#include <stack>
#include <vector>
using namespace std;
void printStack(stack<int> &st)
{
    stack<int> temp;
    while (st.size())
    {
        temp.push(st.top());
        st.pop();
    }
    while (temp.size())
    {
        cout << temp.top() << "  ";
        st.push(temp.top());
        temp.pop();
    }
    cout << endl;
}
void pushAtBottom(int val, stack<int> &st)
{
    vector<int> vec;
    while (st.size())
    {
        vec.push_back(st.top());
        st.pop();
    }
    int n = vec.size();
    st.push(val);
    for (int i = n - 1; i >= 0; i--)
    {
        st.push(vec[i]);
    }
    cout << endl;
}
void printRecursiveReverse(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int x = st.top();
    cout << x << "  ";
    st.pop();
    printRecursiveReverse(st);
    st.push(x);
}
void printRecursive(stack<int> &st) // recursive call ke phle kaam aur baad me kaaam
{
    if (st.size() == 0)
        return;
    int x = st.top();
    st.pop();
    printRecursive(st);
    cout << x << "  ";
    st.push(x);
}
void pushAtBottomRecursively(int val, stack<int> &st)
{
    if (st.size() == 0)
    {
        st.push(val);
        return;
    }

    int x = st.top();
    st.pop();
    pushAtBottomRecursively(val, st);
    st.push(x);
}

void reverserStackRecursively(stack<int> &st)
{ // to reverse the stack recursively we have requried pushatbottom
    if (st.size() == 1)
        return;
    int x = st.top();
    st.pop();
    reverserStackRecursively(st);
    pushAtBottomRecursively(x, st);
}

int main()
{
    stack<int> st;
    stack<int> temp;
    stack<int> temp2;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    printStack(st);
    cout << st.size() << endl;
    // printRecursiveReverse(st);
    // cout << endl
    //      << st.size() << endl;
    // // printStack(st);
    // printRecursive(st);
    // cout << endl
    //      << st.size() << endl;

    reverserStackRecursively(st);
    printStack(st);
    cout << st.size() << endl;

    return 0;
}