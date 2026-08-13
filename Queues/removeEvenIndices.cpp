#include <iostream>
#include <queue>
using namespace std;
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
void removeEvenIndices(queue<int> &q)
{
    int n = q.size();
    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            int x = q.front();
            q.push(x);
        }
        q.pop();
    }
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
    display(q);
    removeEvenIndices(q);
    display(q);

    return 0;
}