#include <iostream>
#include <queue>
#include <stack>
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
int main()
{
    queue<int> q;
    // Push
    // Pop
    // front --> top in stack
    // size and empty
    // back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout<<q.front();
    //  cout<<q.back();
    // cout << q.size() << endl;
    // q.pop();
    // cout << q.front() << endl;
    display(q);
    q.pop();
    display(q);
    // cout<<q.empty(); returns boolean value either 1 or 0

    return 0;
}