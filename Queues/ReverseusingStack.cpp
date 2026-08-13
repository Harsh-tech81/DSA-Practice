#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverseUsingStack(queue<int> &q)
{
    stack<int> st;
    // Empty the queue into stack
    while (q.size())
    {
        int x = q.front();
        st.push(x);
        q.pop();
    }
    // Empty the Stack into queue
    while (st.size())
    {
        q.push(st.top());
        st.pop();
    }
}
void display(queue<int> &q)
{
    int n = q.size();
    while (n)
    {
        int x = q.front();
        cout << x << "  ";
        q.pop();
        q.push(x);
        n--;
    }
    cout << endl;
}
int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverseUsingStack(q);
    display(q);
    reverseUsingStack(q);
    display(q);

    return 0;
}