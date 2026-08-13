#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reorder(queue<int> &q)
{
    stack<int> st;
    int n = q.size();
    // Pop first half of the q to the st
    for (int i = 1; i <= n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // empty the stack into the Queue
    while (st.size())
    {
        q.push(st.top());
        st.pop();
    }
    // Pop the 2nd half (now the first ) of thr q to the st
    for (int i = 1; i <= n / 2; i++)
    {
        st.push(q.front());
        q.pop();
    }
    // Most Imp. step (Interleave one by one )
    while (st.size())
    {
        q.push(st.top());
        st.pop();
        q.push(q.front());
        q.pop();
    }
    // Last step is the reverse the Queue using stack
    while (q.size())
    {
        st.push(q.front());
        q.pop();
    }
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
    q.push(60);
    q.push(70);
    q.push(80);
    display(q);
    reorder(q);
    display(q);

    return 0;
}