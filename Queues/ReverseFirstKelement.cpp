#include <iostream>
#include <queue>
#include <stack>
using namespace std;
void reverseFirstKelement(queue<int> &q, int k)
{
    stack<int> st;
    int n=q.size();
    // Empty the queue of K elements only into the stack
    for (int i = 1; i <= k; i++)
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
    for (int i = 1; i <= n - k; i++)
    {
        int x = q.front();
        q.pop();
        q.push(x);
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
    display(q);
    int k = 4;
    reverseFirstKelement(q, k);
    display(q);

    return 0;
}